#include "Piece.hpp"

#include <algorithm>
#include <iostream>

static Piece& pieceRow(Piece&& piece) { return piece; }

const std::vector<Piece> Piece::m_pieces = std::vector<Piece>{
    pieceRow(Piece(parsePoints("0 0 0 1 0 2 0 3"))),  // 0
    pieceRow(Piece(parsePoints("0 0 0 1 0 2 1 0"))),  // 1
    pieceRow(Piece(parsePoints("0 0 1 0 1 1 1 2"))),  // 2
    pieceRow(Piece(parsePoints("0 0 1 0 1 1 2 1"))),  // 3
    pieceRow(Piece(parsePoints("0 1 1 1 1 0 2 0"))),  // 4
    pieceRow(Piece(parsePoints("0 0 0 1 1 0 1 1"))),  // 5
    pieceRow(Piece(parsePoints("0 0 1 0 1 1 2 0"))),  // 6
};

Piece::Piece(std::vector<Point> points) : m_body(points) {
  const auto min_x =
      std::min_element(m_body.begin(), m_body.end(),
                       [](const Point& a, const Point& b) { return a.x < b.x; })
          ->x;
  const auto max_x =
      std::max_element(m_body.begin(), m_body.end(),
                       [](const Point& a, const Point& b) { return a.x < b.x; })
          ->x;
  m_width = max_x - min_x + 1;

  const auto min_y =
      std::min_element(m_body.begin(), m_body.end(),
                       [](const Point& a, const Point& b) { return a.y < b.y; })
          ->y;
  const auto max_y =
      std::max_element(m_body.begin(), m_body.end(),
                       [](const Point& a, const Point& b) { return a.y < b.y; })
          ->y;
  m_height = max_y - min_y + 1;
}
