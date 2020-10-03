#pragma once

#include "Game.hpp"

class GetReadyState : public GameState {
 public:
  GetReadyState(Game& game);

  void pressButton() override;
  void update(sf::Time Delta);
  void draw(sf::RenderWindow& window);

 private:
  void setText();
  void setLogo();

  sf::Text m_text;
  sf::Sprite m_sprite;
};
