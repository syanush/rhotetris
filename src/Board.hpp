#pragma once

#include <array>

#include "Observable.hpp"
#include "Piece.hpp"

namespace RhoTetris {

enum class Colors { Default, Magenta };

class Board : public Observable {
 public:
  static const int kBoardWidth = 10;
  static const int kBoardHeight = 22;

  void clear();
  void update();
  void makeNewPiece();
  void movePieceLeft();
  void movePieceRight();
  void rotatePiece();
  void hardDrop();

  Colors getCell(int col, int row) const { return m_gameBoard[row][col]; }
  int getRow() const { return m_row; }
  int getCol() const { return m_col; }
  const Piece& getPiece() const { return *m_piece; }

 private:
  std::array<std::array<Colors, kBoardWidth>, kBoardHeight> m_gameBoard;

  const Piece* m_piece;

  // piece position on the board
  int m_row;
  int m_col;

  bool collidesAt(int col, int row);
  void lockPiece();
  bool isCompleteLine(int row) const;
  void clearCompleteLine(int aRow);
  void clearCompleteLines();
  void touchDown();
};

}  // namespace RhoTetris
