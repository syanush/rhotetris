#pragma once

#include "Game.hpp"
#include "Piece.hpp"

namespace RhoTetris {

enum class Colors { Default, Red, Blue, Green, Yellow, Magenta };

sf::Color ToColor(Colors value);

class PlayingState : public GameState {
 public:
  PlayingState(Game& game);

  virtual void initialize() override;
  virtual void handleKeyPressedEvents(sf::Keyboard::Key code) override;
  virtual void handleKeyReleasedEvents(sf::Keyboard::Key code) override;
  virtual void update(sf::Time Delta) override;
  virtual void draw(sf::RenderWindow& window) override;
  void drawPiece(sf::RenderWindow& window, const Piece& piece, int row,
                 int col);

  static const int kBoardWidth = 10;
  static const int kBoardHeight = 22;
  static const int kCellWidth = 16;
  static const int kCellHeight = 16;
  static const int kOriginX = 200;
  static const int kOriginY = 400;

 private:
  std::array<std::array<Colors, kBoardWidth>, kBoardHeight> m_gameBoard;
  sf::RectangleShape m_rectangle;

  const Piece* m_piece;
  int m_row;
  int m_col;

  sf::Time m_elapsedTime;
  sf::Clock m_clock;
  sf::Time m_deltaTime;

  void makeNewPiece();
};

}  // namespace RhoTetris