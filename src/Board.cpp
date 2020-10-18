#include "Board.hpp"

using namespace RhoTetris;

void Board::clear() {
  for (int row = 0; row < kBoardHeight; ++row) {
    for (int col = 0; col < kBoardWidth; ++col) {
      m_gameBoard[row][col] = Colors::Default;
    }
  }
}

bool Board::collidesAt(int col, int row) {
  if (row < 0) return true;

  for (const auto& [x, y] : m_piece->getBody()) {
    auto bCol = col + x;
    auto bRow = row + y;
    auto color = m_gameBoard[bRow][bCol];
    if (color != Colors::Default) return true;
  }

  return false;
}

void Board::hardDrop() {
  while (!collidesAt(m_col, m_row - 1)) --m_row;
  touchDown();
}

void Board::lockPiece() {
  for (const auto& [x, y] : m_piece->getBody()) {
    auto bCol = m_col + x;
    auto bRow = m_row + y;
    m_gameBoard[bRow][bCol] = Colors::Magenta;
  }
}

void Board::clearCompleteLine(int aRow) {
  for (int row = aRow; row < kBoardHeight - 1; ++row) {
    std::move(begin(m_gameBoard[row + 1]), end(m_gameBoard[row + 1]),
              begin(m_gameBoard[row]));
  }
}

void Board::clearCompleteLines() {
  for (int bRow = kBoardHeight - 1 - 2; bRow >= 0; --bRow)
    if (isCompleteLine(bRow)) clearCompleteLine(bRow);
}

bool Board::isCompleteLine(int row) const {
  for (int col = 0; col < kBoardWidth; ++col) {
    if (m_gameBoard[row][col] == Colors::Default) return false;
  }
  return true;
}

const Piece* getNextPiece() {
  auto& pieces = Piece::getPieces();
  const int index = rand() % 7;  // number of different pieces
  const Piece* piece = &pieces[index];
  while (piece->getHeight() > 2) piece = piece->nextRotation();
  return piece;
}

void Board::makeNewPiece() {
  m_piece = getNextPiece();
  m_col = kBoardWidth / 2 - 1;
  m_row = kBoardHeight - 2;
}

void Board::movePieceLeft() {
  if (collidesAt(m_col - 1, m_row)) return;

  if (m_col > 0) m_col -= 1;
}

void Board::movePieceRight() {
  if (collidesAt(m_col + 1, m_row)) return;

  const auto maxCol = kBoardWidth - m_piece->getWidth();

  if (m_col < maxCol) m_col += 1;
}

void Board::rotatePiece() {
  auto oldCenter = m_piece->getWidth() / 2;
  m_piece = m_piece->nextRotation();
  auto newCenter = m_piece->getWidth() / 2;

  // Preserve piece center position
  m_col += oldCenter;
  m_col -= newCenter;

  // Left kick
  if (m_col < 0) m_col = 0;

  // Right kick
  const auto maxCol = kBoardWidth - m_piece->getWidth();
  if (m_col > maxCol) m_col = maxCol;
}

void Board::touchDown() {
  lockPiece();
  clearCompleteLines();
  makeNewPiece();

  if (collidesAt(m_col, m_row)) {
    handleGameOverEvent();
  }
}

void Board::update() {
  if (collidesAt(m_col, m_row - 1)) {
    touchDown();
  } else {
    m_row -= 1;
  }
}
