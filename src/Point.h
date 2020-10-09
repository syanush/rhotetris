#pragma once

#include <vector>
#include <istream>

struct Point {
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  int x;
  int y;
};

std::vector<Point> parsePoints(std::string_view strPoints);
std::istream& operator>>(std::istream& input, Point& point);