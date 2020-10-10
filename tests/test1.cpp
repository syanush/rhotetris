#include <cmath>

#include "gtest/gtest.h"
#include "Piece.hpp"

namespace {
// The test case name and the test name.
// You should not use underscore (_) in the names.

TEST(PieceTestCase, CheckPieces) {
  auto& pieces = Piece::getPieces();
  auto& b0 = pieces[0].getBody();
  // 0 0 0 1 0 2 0 3
  EXPECT_EQ(0, b0[0].x);
  EXPECT_EQ(0, b0[0].y);
  EXPECT_EQ(0, b0[1].x);
  EXPECT_EQ(1, b0[1].y);
  EXPECT_EQ(0, b0[2].x);
  EXPECT_EQ(2, b0[2].y);
  EXPECT_EQ(0, b0[3].x);
  EXPECT_EQ(3, b0[3].y);
}

TEST(PieceTestCase, CheckWidth) {
  auto& pieces = Piece::getPieces();
  auto& b0 = pieces[0].getBody();
  auto width = pieces[0].getWidth();
  EXPECT_EQ(1, width);
}

TEST(PieceTestCase, CheckHeight) {
  auto& pieces = Piece::getPieces();
  auto& b0 = pieces[0].getBody();
  auto height = pieces[0].getHeight();
  EXPECT_EQ(4, height);
}

TEST(PointTestCase, ComparePoints) {
  EXPECT_TRUE(Point(1, 1) < Point(2, 1));
  EXPECT_TRUE(Point(1, 1) < Point(1, 2));
  EXPECT_TRUE(Point(1, 1) <= Point(1, 1));
}

TEST(PointTestCase, CompareBodies) {
  std::vector<Point> b1{Point(1, 1), Point(2, 1), Point(1, 2)};
  std::vector<Point> b2{Point(2, 1), Point(1, 2), Point(1, 1)};
}

}  // namespace
