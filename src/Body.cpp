#include "Body.hpp"

#include <algorithm>
#include <cassert>

using namespace RhoTetris;

size_t RhoTetris::getWidth(const Body& body) {
  std::vector<int> xValues;
  for (const auto& [x, y] : body) xValues.push_back(x);
  auto width = getDiameter(xValues);
  return width;
}

size_t RhoTetris::getHeight(const Body& body) {
  std::vector<int> yValues;
  for (const auto& [x, y] : body) yValues.push_back(y);
  auto height = getDiameter(yValues);
  return height;
}

size_t RhoTetris::getDiameter(const std::vector<int>& collection) {
  auto minValue = *std::min_element(collection.begin(), collection.end());
  auto maxValue = *std::max_element(collection.begin(), collection.end());
  auto diameter = maxValue - minValue + 1;
  return diameter;
}

/*
 * Rotate the body 90 degrees counterclockwise
 */
Body RhoTetris::rotate(const Body& body) {
  auto height = getHeight(body);
  Body rotatedBody;
  for (const auto& [x, y] : body) rotatedBody.emplace_back(height - y - 1, x);
  return rotatedBody;
}

bool RhoTetris::operator==(const Body& lhs, const Body& rhs) {
  if (lhs.size() != rhs.size()) return false;

  Body lhs1 = Body(lhs);
  Body rhs1 = Body(rhs);
  std::sort(lhs1.begin(), lhs1.end());
  std::sort(rhs1.begin(), rhs1.end());

  const auto areEqual = std::equal(lhs1.begin(), lhs1.end(), rhs1.begin());
  return areEqual;
}

bool RhoTetris::operator!=(const Body& lhs, const Body& rhs) {
  return !(lhs == rhs);
}

Skirt RhoTetris::getSkirt(const Body& body) {
  const auto& width = getWidth(body);
  Skirt skirt;

  for (int x = 0; x < width; ++x) {
    std::vector<int> yValues;
    for (const auto& [x1, y1] : body)
      if (x1 == x) yValues.push_back(y1);

    assert(!yValues.empty());
    auto yMin = *std::min_element(yValues.begin(), yValues.end());
    skirt.push_back(yMin);
  }

  return skirt;
}
