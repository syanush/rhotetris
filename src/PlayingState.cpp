#include "PlayingState.hpp"

PlayingState::PlayingState(Game& game) : GameState(game) {
  m_rectangle =
      sf::RectangleShape(sf::Vector2f(kCellWidth - 1, kCellHeight - 1));

  for (int row = 0; row < kBoardHeight; ++row) {
    for (int col = 0; col < kBoardWidth; ++col) {
      m_gameBoard[row][col] = Colors::Default;
    }
  }

  m_gameBoard[3][4] = Colors::Green;
  m_gameBoard[3][5] = Colors::Green;
  m_gameBoard[3][6] = Colors::Green;
  m_gameBoard[4][5] = Colors::Green;

  m_gameBoard[0][0] = Colors::Blue;
  m_gameBoard[kBoardHeight - 1][0] = Colors::Blue;
  m_gameBoard[0][kBoardWidth - 1] = Colors::Blue;
  m_gameBoard[kBoardHeight - 1][kBoardWidth - 1] = Colors::Blue;
}

void PlayingState::draw(sf::RenderWindow& window) {
  for (int row = 0; row < kBoardHeight; ++row) {
    for (int col = 0; col < kBoardWidth; ++col) {
      const auto position = sf::Vector2f(kOriginX + kCellWidth * col,
                                         kOriginY - kCellHeight * row);
      const auto color = ToColor(m_gameBoard[row][col]);
      m_rectangle.setPosition(position);
      m_rectangle.setFillColor(color);
      window.draw(m_rectangle);
    }
  }
}

void PlayingState::update(sf::Time delta) {}

void PlayingState::handleKeyboardEvents(sf::Keyboard::Key code) {
  if (code == sf::Keyboard::Escape)
    getGame().changeGameState(GameState::GetReady);
  if (code == sf::Keyboard::R) getGame().changeGameState(GameState::EndGame);
}

sf::Color ToColor(Colors value) {
  switch (value) {
    case Colors::Default:
      return sf::Color::Transparent;
    case Colors::Red:
      return sf::Color::Red;
    case Colors::Blue:
      return sf::Color::Blue;
    case Colors::Green:
      return sf::Color::Green;
    case Colors::Yellow:
      return sf::Color::Yellow;
    case Colors::Magenta:
      return sf::Color::Magenta;
    default:
      throw std::invalid_argument("Unknown color");
  }
}
