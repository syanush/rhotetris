#include "Piece.hpp"

#include <algorithm>

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
  Piece rotatedPiece{::rotate(getBody())};
  return rotatedPiece;
}

// TODO: create correct realization
Skirt RhoTetris::getSkirt(const Body& body) { return Skirt(); }

size_t RhoTetris::getDiameter(const std::vector<int>& collection) {
  auto minValue = *std::min_element(collection.begin(), collection.end());
  auto maxValue = *std::max_element(collection.begin(), collection.end());
  auto diameter = maxValue - minValue + 1;
  return diameter;
}

size_t RhoTetris::getWidth(const Body& body) {
  std::vector<int> xValues;
  for (const auto& [x, y] : body) xValues.push_back(x);
  auto width = getDiameter(xValues);
  return width;
}

size_t RhoTetris::getHeight(const Body& body) {
  std::vector<int> yValues;
  for (const auto& [x, y] : body) yValues.push_back(y);
  auto height = getDiameter(yValues);
  return height;
}

/*
 * Rotate the body 90 degrees counterclockwise
 */
Body RhoTetris::rotate(const Body& body) {
  auto height = getHeight(body);
  Body rotatedBody;
  for (const auto& [x, y] : body) rotatedBody.emplace_back(height - y - 1, x);
  return rotatedBody;
}

bool RhoTetris::operator==(const Body& lhs, const Body& rhs) {
  if (lhs.size() != rhs.size()) return false;

  Body lhs1 = Body(lhs);
  Body rhs1 = Body(rhs);
  std::sort(lhs1.begin(), lhs1.end());
  std::sort(rhs1.begin(), rhs1.end());

  const auto areEqual = std::equal(lhs1.begin(), lhs1.end(), rhs1.begin());
  return areEqual;
}

bool RhoTetris::operator!=(const Body& lhs, const Body& rhs) {
  return !(lhs == rhs);
}
