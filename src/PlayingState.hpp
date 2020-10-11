#pragma once

#include "Game.hpp"
#include "Piece.hpp"

namespace RhoTetris {

enum class Colors { Default, Red, Blue, Green, Yellow, Magenta };

sf::Color ToColor(Colors value);

class PlayingState : public GameState {
 public:
  PlayingState(Game& game);

  void handleKeyboardEvents(sf::Keyboard::Key code) override;
  void update(sf::Time Delta) override;
  void draw(sf::RenderWindow& window) override;
  void drawPiece(sf::RenderWindow& window, const Piece& piece, int row,
                 int col);

  static const size_t kBoardWidth = 10;
  static const size_t kBoardHeight = 22;
  static const int kCellWidth = 16;
  static const int kCellHeight = 16;
  static const int kOriginX = 200;
  static const int kOriginY = 400;

 private:
  std::array<std::array<Colors, kBoardWidth>, kBoardHeight> m_gameBoard;
  sf::RectangleShape m_rectangle;
};

}  // namespace RhoTetris