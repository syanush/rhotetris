#pragma once

#include <SFML/Graphics.hpp>

namespace RhoTetris {

template <typename T>
void centerOrigin(T &drawable) {
  sf::FloatRect bound = drawable.getLocalBounds();
  drawable.setOrigin(bound.width / 2, bound.height / 2);
}

}  // namespace RhoTetris
