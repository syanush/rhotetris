#include "Point.hpp"

#include <sstream>

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
