#pragma once

#include "Game.hpp"

class PlayingState : public GameState {
 public:
  PlayingState(Game& game);
  ~PlayingState();

  void handleKeyboardEvents(sf::Keyboard::Key code) override;
  void update(sf::Time Delta) override;
  void draw(sf::RenderWindow& window) override;

 private:
  sf::RenderTexture m_scene;
  sf::Sprite m_picture;
  int m_score;
};