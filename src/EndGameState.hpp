#pragma once

#include "Game.hpp"

namespace RhoTetris {

class EndGameState : public GameState {
 public:
  EndGameState(Game& game);
  void handleKeyboardEvents(sf::Keyboard::Key code) override;
  void update(sf::Time Delta) override;
  void draw(sf::RenderWindow& window) override;

 private:
  sf::Text m_text;

  void setText();
};

}  // namespace RhoTetris