#pragma once

#include "Game.hpp"

class PlayingState : public GameState {
 public:
  PlayingState(Game* game);
  ~PlayingState();

  void update(sf::Time Delta);
  void draw(sf::RenderWindow& window);

 private:
  sf::RenderTexture m_scene;

  int m_score;
};
