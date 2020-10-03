#pragma once

#include "Game.hpp"

class GetReadyState : public GameState {
 public:
  GetReadyState(Game* game);

  void update(sf::Time Delta);
  void draw(sf::RenderWindow& window);

 private:
  sf::Text m_text;
};
