#pragma once

#include <array>
#include <initializer_list>
#include <memory>
#include <string_view>
#include <vector>

#include "Point.hpp"

class Piece final {
 public:
  inline int getWidth() const { return m_width; }
  inline int getHeight() const { return m_height; }
  inline const std::vector<Point>& getBody() const { return m_body; }
  inline const std::vector<int>& getSkirt() const { return m_skirt; }
  static const std::vector<Piece>& getPieces() { return m_pieces; }

  inline const Piece* nextRotation() const { return m_next; }
  bool equals(const Piece& other);

 private:
  int m_width;
  int m_height;
  std::vector<Point> m_body;
  std::vector<int> m_skirt;
  Piece* m_next;
  static const std::vector<Piece> m_pieces;

  Piece(std::vector<Point> points);
};
