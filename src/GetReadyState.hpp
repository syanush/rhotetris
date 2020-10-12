#pragma once

#include "Game.hpp"

namespace RhoTetris {

class GetReadyState : public GameState {
 public:
  GetReadyState(Game& game);

  void handleKeyPressedEvents(sf::Keyboard::Key code) override;
  void update(sf::Time Delta);
  void draw(sf::RenderWindow& window);

 private:
  sf::Text m_text;
  sf::Sprite m_sprite;

  void setText();
  void setLogo();
};

}  // namespace RhoTetris
