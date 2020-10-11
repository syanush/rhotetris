#pragma once

#include <array>
#include <initializer_list>
#include <memory>
#include <string_view>
#include <vector>

#include "Point.hpp"

namespace RhoTetris {

class Piece;
Piece& pieceRow(Piece&& piece);

using Pieces = std::array<Piece, 7>;
using Body = std::vector<Point>;  // TODO: Move to Body.hpp/cpp
using Skirt = std::vector<int>;

size_t getWidth(const Body& body);
size_t getHeight(const Body& body);
size_t getDiameter(const std::vector<int>& collection);
Body rotate(const Body& body);
Skirt getSkirt(const Body& body);
bool operator==(const Body& lhs, const Body& rhs);
bool operator!=(const Body& thisBody, const Body& otherBody);

class Piece final {
 public:
  inline int getWidth() const { return m_width; }
  inline int getHeight() const { return m_height; }
  inline const Body& getBody() const { return m_body; }
  inline const Skirt& getSkirt() const { return m_skirt; }
  static const Pieces& getPieces() { return m_pieces; }

  inline const Piece& nextRotation() const { return *m_next; }
  bool operator==(const Piece& other) const;
  bool operator!=(const Piece& other) const;

 private:
  Body m_body;
  int m_width;
  int m_height;
  Skirt m_skirt;
  Piece* m_next;

  static const Pieces m_pieces;

  Piece(Body body);
  Piece rotate();
  friend Piece& pieceRow(Piece&& piece);
};

}  // namespace RhoTetris