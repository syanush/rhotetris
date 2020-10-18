#pragma once

#include "Board.hpp"
#include "Game.hpp"
#include "IObserver.hpp"
#include "Piece.hpp"

namespace RhoTetris {

class PlayingState : public GameState, public IObserver {
 public:
  PlayingState(Game& game);

  virtual void initialize() override;
  virtual void handleKeyPressedEvents(sf::Keyboard::Key code) override;
  virtual void handleKeyReleasedEvents(sf::Keyboard::Key code) override;
  virtual void update(sf::Time Delta) override;
  virtual void draw(sf::RenderWindow& window) override;
  void drawPiece(sf::RenderWindow& window, const Piece& piece, int row,
                 int col);
  void drawBoardOutline(sf::RenderWindow& window);
  void drawBoard(sf::RenderWindow& window);

  void notify() override;

  static const int kCellWidth = 16;
  static const int kCellHeight = 16;
  static const int kOriginX = 200;
  static const int kOriginY = 400;

 private:
  Board m_board;

  sf::Time m_elapsedTime;
  sf::Clock m_clock;
  sf::Time m_deltaTime;

  sf::RectangleShape m_rectangle;
};

}  // namespace RhoTetris