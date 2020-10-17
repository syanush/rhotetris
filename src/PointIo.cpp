#include "PointIo.hpp"

#include <sstream>

using namespace RhoTetris;

std::vector<Point> RhoTetris::parsePoints(std::string_view strPoints) {
  std::istringstream input(std::string(strPoints), std::ios_base::in);
  std::vector<Point> points;
  Point point;
  while (input >> point) {
    points.push_back(point);
  }
  return points;
}

std::istream& RhoTetris::operator>>(std::istream& input, Point& point) {
  input >> point.x >> point.y;
  return input;
}
