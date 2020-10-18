#include "PlayingState.hpp"

using namespace RhoTetris;

PlayingState::PlayingState(Game& game) : GameState(game) {
  m_board.register_observer(*this);
}

void PlayingState::drawPiece(sf::RenderWindow& window, const Piece& piece,
                             int row, int col) {
  const auto position =
      sf::Vector2f(kOriginX + kCellWidth * col, kOriginY - kCellHeight * row);
  const auto color = sf::Color::Magenta;
  m_rectangle.setFillColor(color);

  const auto& body = piece.getBody();
  for (const auto& [x, y] : body) {
    // TODO: Extract coordinate system transformations
    auto pos = position + sf::Vector2f(x * kCellWidth, -y * kCellHeight);
    m_rectangle.setPosition(pos);
    window.draw(m_rectangle);
  }
}

void PlayingState::drawBoardOutline(sf::RenderWindow& window) {
  m_rectangle.setSize(sf::Vector2f{5, Board::kBoardHeight * kCellHeight + 2});
  m_rectangle.setFillColor(sf::Color::Yellow);

  m_rectangle.setPosition(sf::Vector2f{
      kOriginX - 6, kOriginY - (Board::kBoardHeight - 1) * kCellHeight});
  window.draw(m_rectangle);

  m_rectangle.setPosition(
      sf::Vector2f{kOriginX + Board::kBoardWidth * kCellWidth + 1,
                   kOriginY - (Board::kBoardHeight - 1) * kCellHeight});
  window.draw(m_rectangle);

  m_rectangle.setSize(sf::Vector2f{Board::kBoardWidth * kCellWidth + 12, 5});
  m_rectangle.setPosition(
      sf::Vector2f{kOriginX - 6, kOriginY + kCellHeight + 1});
  window.draw(m_rectangle);

  m_rectangle =
      sf::RectangleShape(sf::Vector2f(kCellWidth - 1, kCellHeight - 1));
}

sf::Color ToColor(Colors value) {
  switch (value) {
    case Colors::Default:
      return sf::Color::Transparent;
    case Colors::Magenta:
      return sf::Color::Magenta;
    default:
      throw std::invalid_argument("Unknown value");
  }
}

void PlayingState::drawBoard(sf::RenderWindow& window) {
  for (int row = 0; row < Board::kBoardHeight; ++row) {
    for (int col = 0; col < Board::kBoardWidth; ++col) {
      const auto position = sf::Vector2f(kOriginX + kCellWidth * col,
                                         kOriginY - kCellHeight * row);
      const auto cell = m_board.getCell(col, row);
      const auto color = ToColor(cell);
      m_rectangle.setPosition(position);
      m_rectangle.setFillColor(color);
      window.draw(m_rectangle);
    }
  }
}

void PlayingState::draw(sf::RenderWindow& window) {
  drawBoardOutline(window);
  drawBoard(window);
  drawPiece(window, m_board.getPiece(), m_board.getRow(), m_board.getCol());
}

void PlayingState::update(sf::Time delta) {
  m_elapsedTime += m_clock.restart();

  while (m_elapsedTime >= m_deltaTime) {
    m_board.update();

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
      m_board.movePieceLeft();
      break;
    case sf::Keyboard::Right:
      m_board.movePieceRight();
      break;
    case sf::Keyboard::Up:
      m_board.rotatePiece();
      break;
    case sf::Keyboard::Down:
      // soft drop
      m_deltaTime = sf::seconds(0.1);
      break;
    case sf::Keyboard::Space:
      m_board.hardDrop();
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

void PlayingState::initialize() {
  m_deltaTime = sf::seconds(0.5);
  m_board.clear();
  m_board.makeNewPiece();
}

void PlayingState::notify() { getGame().changeGameState(GameState::EndGame); }
