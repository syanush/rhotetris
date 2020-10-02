#pragma once

#include <SFML/Graphics.hpp>

class Game;

class GameState {
 public:
  enum State { GetReady, Playing, Count };

  GameState(Game* game);
  Game* getGame() const;

  virtual void update(sf::Time delta) = 0;
  virtual void draw(sf::RenderWindow& window) = 0;

 private:
  Game* m_game;
};

class GetReadyState : public GameState {
 public:
  GetReadyState(Game* game, GameState* playingState);

  void update(sf::Time Delta);
  void draw(sf::RenderWindow& window);

 private:
  sf::Text m_text;
};

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
