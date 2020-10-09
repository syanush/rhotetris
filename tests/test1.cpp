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

TEST(ExampleTestCase, ExampleTest) { EXPECT_EQ(1, 1); }

TEST(ExampleTestCase, SinusTest) { EXPECT_FLOAT_EQ(1.0, sin(M_PI_2)); }

TEST(ExampleTestCase, BoolTest) {
  EXPECT_TRUE(true);
  EXPECT_FALSE(false);
}

}  // namespace
