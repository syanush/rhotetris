#include "Piece.hpp"

#include "PointIo.hpp"

using namespace RhoTetris;

/*
 * Wires up rotated pieces with the initial piece.
 * It is used only during initialization of static data.
 */
Piece& RhoTetris::pieceRow(Piece&& piece) {
  auto initial = new Piece(std::move(piece));
  auto tmp = initial;
  do {
    tmp->m_next = new Piece(std::move(tmp->rotate()));
    tmp = tmp->m_next;
  } while (*tmp != *initial);

  tmp->m_next = initial->m_next;
  delete initial;
  initial = nullptr;
  return *tmp;
}

const Pieces Piece::m_pieces = Pieces{
    pieceRow(Piece(parsePoints("0 0 0 1 0 2 0 3"))),  // 0
    pieceRow(Piece(parsePoints("0 0 0 1 0 2 1 0"))),  // 1
    pieceRow(Piece(parsePoints("0 0 1 0 1 1 1 2"))),  // 2
    pieceRow(Piece(parsePoints("0 0 1 0 1 1 2 1"))),  // 3
    pieceRow(Piece(parsePoints("0 1 1 1 1 0 2 0"))),  // 4
    pieceRow(Piece(parsePoints("0 0 0 1 1 0 1 1"))),  // 5
    pieceRow(Piece(parsePoints("0 0 1 0 1 1 2 0"))),  // 6
};

/*
 * Computes width/height/skirt
 */
Piece::Piece(Body body) : m_body(body) {
  m_width = RhoTetris::getWidth(body);
  m_height = RhoTetris::getHeight(body);
  m_skirt = RhoTetris::getSkirt(body);
}

bool Piece::operator==(const Piece& other) const {
  if (this == &other) return true;
  return Body(getBody()) == Body(other.getBody());
}

bool Piece::operator!=(const Piece& other) const { return !(*this == other); }

/*
 * Create rotated piece
 */
Piece Piece::rotate() {
  Piece rotatedPiece{RhoTetris::rotate(getBody())};
  return rotatedPiece;
}
