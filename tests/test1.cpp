#include "gtest/gtest.h"
#include "Piece.hpp"

using namespace RhoTetris;

namespace {
// The test case name and the test name.
// You should not use underscore (_) in the names.

TEST(PieceTestCase, CheckPieces) {
  auto& pieces = Piece::getPieces();
  Body actual = pieces[0].getBody();
  Body expected {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
  EXPECT_EQ(expected, actual);
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

TEST(PieceTestCase, CheckSkirt0) {
  const auto& pieces = Piece::getPieces();
  const auto& b0 = pieces[0].getBody();
  const auto& actual = RhoTetris::getSkirt(b0);
  const Skirt expected{0};
  EXPECT_EQ(expected, actual);
}

TEST(PieceTestCase, CheckSkirt4) {
  const auto& pieces = Piece::getPieces();
  const auto& b4 = pieces[4].getBody();
  const auto& actual = RhoTetris::getSkirt(b4);
  const Skirt expected{1, 0, 0};
  EXPECT_EQ(expected, actual);
}

TEST(PointTestCase, ComparePoints) {
  EXPECT_TRUE(Point(1, 1) < Point(2, 1));
  EXPECT_TRUE(Point(1, 1) < Point(1, 2));
  EXPECT_TRUE(Point(1, 1) <= Point(1, 1));
}

TEST(PieceTestCase, CompareBodies) {
  std::vector<Point> b1{Point(1, 1), Point(2, 1), Point(1, 2)};
  std::vector<Point> b2{Point(2, 1), Point(1, 2), Point(1, 1)};
  EXPECT_EQ(b1, b2);
}

TEST(PieceTestCase, RotateBodies) {
  Body body{Point(0, 0)};
  Body rotated = RhoTetris::rotate(body);
  EXPECT_EQ(body, rotated);
}

void ShouldHaveRotationIndex1(size_t pieceIndex) {
  auto& pieces = Piece::getPieces();
  auto& piece = pieces[pieceIndex];
  Piece rotated1 = piece.nextRotation();
  EXPECT_EQ(piece, rotated1);
}

void ShouldHaveRotationIndex2(size_t pieceIndex) {
  auto& pieces = Piece::getPieces();
  auto& piece = pieces[pieceIndex];
  Piece rotated1 = piece.nextRotation();
  EXPECT_NE(piece, rotated1);
  Piece rotated2 = rotated1.nextRotation();
  EXPECT_EQ(piece, rotated2);
}

void ShouldHaveRotationIndex4(size_t pieceIndex) {
  auto& pieces = Piece::getPieces();
  auto& piece = pieces[pieceIndex];
  Piece rotated1 = piece.nextRotation();
  EXPECT_NE(piece, rotated1);
  Piece rotated2 = rotated1.nextRotation();
  EXPECT_NE(piece, rotated2);
  Piece rotated3 = rotated2.nextRotation();
  EXPECT_NE(piece, rotated3);
  Piece rotated4 = rotated3.nextRotation();
  EXPECT_EQ(piece, rotated4);
}

TEST(PieceTestCase, TestRotations) {
  auto& pieces = Piece::getPieces();
  ShouldHaveRotationIndex2(0);
  ShouldHaveRotationIndex4(1);
  ShouldHaveRotationIndex4(2);
  ShouldHaveRotationIndex2(3);
  ShouldHaveRotationIndex2(4);
  ShouldHaveRotationIndex1(5);
  ShouldHaveRotationIndex4(6);
}

}  // namespace
