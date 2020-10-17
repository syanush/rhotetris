#pragma once

#include <istream>
#include <string_view>
#include <vector>

namespace RhoTetris {

struct Point {
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const Point& point) const;
  bool operator>(const Point& point) const;
  bool operator<=(const Point& point) const;
  bool operator>=(const Point& point) const;
  bool operator==(const Point& point) const;
  bool operator!=(const Point& point) const;

  int x;
  int y;
};

}  // namespace RhoTetris
