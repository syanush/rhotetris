#pragma once

#include "Game.hpp"

class PlayingState : public GameState {
 public:
  PlayingState(Game& game);

  void handleKeyboardEvents(sf::Keyboard::Key code) override;
  void update(sf::Time Delta) override;
  void draw(sf::RenderWindow& window) override;

  const size_t m_boardWidth = 10;
  const size_t m_boardHeight = 22;

 private:
};
