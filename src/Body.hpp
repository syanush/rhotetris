#pragma once

#include "Point.hpp"

namespace RhoTetris {

using Body = std::vector<Point>;
using Skirt = std::vector<int>;

size_t getWidth(const Body& body);
size_t getHeight(const Body& body);
size_t getDiameter(const std::vector<int>& collection);
Body rotate(const Body& body);
bool operator==(const Body& lhs, const Body& rhs);
bool operator!=(const Body& thisBody, const Body& otherBody);

/*
 * Returns the skirt of the body.
 * The skirt is the lowest y value for every x value in the piece coordinate
 * system.
 */
Skirt getSkirt(const Body& body);

}  // namespace RhoTetris
