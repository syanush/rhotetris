#include "Point.hpp"

using namespace RhoTetris;

bool Point::operator<(const Point& point) const {
  return x < point.x || (x == point.x && y < point.y);
}

bool Point::operator>(const Point& point) const {
  return x > point.x || (x == point.x && y > point.y);
}

bool Point::operator<=(const Point& point) const { return !(*this > point); }

bool Point::operator>=(const Point& point) const { return !(*this < point); }

bool Point::operator==(const Point& point) const {
  if (this == &point) return true;

  return x == point.x && y == point.y;
}

bool Point::operator!=(const Point& point) const { return !(*this == point); }
