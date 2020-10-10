#include "Point.hpp"

#include <sstream>

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

std::vector<Point> parsePoints(std::string_view strPoints) {
  std::istringstream input(std::string(strPoints), std::ios_base::in);
  std::vector<Point> points;
  Point point;
  while (input >> point) {
    points.push_back(point);
  }
  return points;
}

std::istream& operator>>(std::istream& input, Point& point) {
  input >> point.x >> point.y;
  return input;
}
