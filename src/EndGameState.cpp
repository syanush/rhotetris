#include "EndGameState.hpp"

#include "Helpers.hpp"

EndGameState::EndGameState(Game& game) : GameState(game) { setText(); }

void EndGameState::update(sf::Time Delta) {}

void EndGameState::draw(sf::RenderWindow& window) { window.draw(m_text); }

void EndGameState::setText() {
  m_text.setFont(getGame().getFont());
  m_text.setString("Game over");
  m_text.setCharacterSize(14);
  centerOrigin(m_text);
  m_text.setPosition(240, 240);
}

void EndGameState::handleKeyboardEvents(sf::Keyboard::Key code) {
  if (code == sf::Keyboard::Escape)
    getGame().changeGameState(GameState::GetReady);
}
