#include "GetReadyState.hpp"

#include "Helpers.hpp"

GetReadyState::GetReadyState(Game& game) : GameState(game), m_game(game) {
  SetText();
}

void GetReadyState::update(sf::Time delta) {}

void GetReadyState::draw(sf::RenderWindow& window) { window.draw(m_text); }

void GetReadyState::SetText() {
  m_text.setFont(m_game.getFont());
  m_text.setString("Press Start when you're ready...");
  m_text.setCharacterSize(14);
  centerOrigin(m_text);
  m_text.setPosition(240, 240);
}
