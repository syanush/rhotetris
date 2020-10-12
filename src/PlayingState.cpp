#include "PlayingState.hpp"

using namespace RhoTetris;

PlayingState::PlayingState(Game& game) : GameState(game) {
  m_deltaTime = sf::seconds(0.5);

  m_rectangle =
      sf::RectangleShape(sf::Vector2f(kCellWidth - 1, kCellHeight - 1));

  for (int row = 0; row < kBoardHeight; ++row) {
    for (int col = 0; col < kBoardWidth; ++col) {
      m_gameBoard[row][col] = Colors::Default;
    }
  }

  m_gameBoard[0][0] = Colors::Blue;
  m_gameBoard[kBoardHeight - 1][0] = Colors::Blue;
  m_gameBoard[0][kBoardWidth - 1] = Colors::Blue;
  m_gameBoard[kBoardHeight - 1][kBoardWidth - 1] = Colors::Blue;
}

void PlayingState::drawPiece(sf::RenderWindow& window, const Piece& piece,
                             int row, int col) {
  const auto position =
      sf::Vector2f(kOriginX + kCellWidth * col, kOriginY - kCellHeight * row);
  const auto color = sf::Color::Cyan;
  m_rectangle.setFillColor(color);

  const auto& body = piece.getBody();
  for (const auto& [x, y] : body) {
    // TODO: Extract coordinate system transformations
    auto pos = position + sf::Vector2f(x * kCellWidth, -y * kCellHeight);
    m_rectangle.setPosition(pos);
    window.draw(m_rectangle);
  }
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

  // Showcase
  auto& pieces = Piece::getPieces();
  drawPiece(window, *m_piece, m_row, m_col);
}

void PlayingState::update(sf::Time delta) {
  m_elapsedTime += m_clock.restart();

  while (m_elapsedTime >= m_deltaTime) {
    // do action

    if (m_row == 0) {
      makeNewPiece();
    }

    m_row -= 1;

    // Substract the time consumed
    m_elapsedTime -= m_deltaTime;
  }
}

void PlayingState::handleKeyPressedEvents(sf::Keyboard::Key code) {
  switch (code) {
    case sf::Keyboard::Escape:
      getGame().changeGameState(GameState::GetReady);
      break;
    case sf::Keyboard::R:
      getGame().changeGameState(GameState::EndGame);
      break;
    case sf::Keyboard::Left:
      m_col -= 1;
      break;
    case sf::Keyboard::Right:
      m_col += 1;
      break;
    case sf::Keyboard::Up:
      m_piece = m_piece->nextRotation();
      break;
    case sf::Keyboard::Down:
      m_deltaTime = sf::seconds(0.1);
      break;
  }
}

void PlayingState::handleKeyReleasedEvents(sf::Keyboard::Key code) {
  switch (code) {
    case sf::Keyboard::Down:
      m_deltaTime = sf::seconds(0.5);
      break;
  }
}

const Piece* getNextPiece() {
  auto& pieces = Piece::getPieces();
  const int index = rand() % 7;
  const Piece* piece = &pieces[index];
  while (piece->getHeight() > 2) piece = piece->nextRotation();
  return piece;
}

void PlayingState::makeNewPiece() {
  m_piece = getNextPiece();
  m_col = 5;
  m_row = 20;
}

void PlayingState::initialize() { makeNewPiece(); }

// TODO: Move to Colors.hpp/cpp
sf::Color RhoTetris::ToColor(Colors value) {
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
