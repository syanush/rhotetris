#pragma once
#include "Point.hpp"

namespace RhoTetris {

std::vector<Point> parsePoints(std::string_view strPoints);
std::istream& operator>>(std::istream& input, Point& point);

}  // namespace RhoTetris
