#pragma once

#include <SFML/Graphics.hpp>

namespace RhoTetris {

class Game;

class GameState {
 public:
  enum State { GetReady, Playing, EndGame, Count };

  GameState(Game& game);
  Game& getGame() const;

  virtual void handleKeyPressedEvents(sf::Keyboard::Key code) = 0;
  virtual void handleKeyReleasedEvents(sf::Keyboard::Key code){};

  virtual void update(sf::Time delta) = 0;
  virtual void draw(sf::RenderWindow& window) = 0;
  virtual void initialize(){};

 private:
  Game& m_game;
};

}  // namespace RhoTetris
