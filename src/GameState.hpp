#pragma once

#include <SFML/Graphics.hpp>

class Game;

class GameState {
 public:
  enum State { GetReady, Playing, Count };

  GameState(Game& game);
  Game& getGame() const;

  virtual void update(sf::Time delta) = 0;
  virtual void draw(sf::RenderWindow& window) = 0;

 private:
  Game& m_game;
};
