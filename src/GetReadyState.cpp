#include "GetReadyState.hpp"

#include "Helpers.hpp"

GetReadyState::GetReadyState(Game *game) : GameState(game) {
  m_text.setFont(game->getFont());
  m_text.setString("Press Start when you're ready...");
  m_text.setCharacterSize(14);

  centerOrigin(m_text);
  m_text.setPosition(240, 240);
}

void GetReadyState::update(sf::Time delta) {}

void GetReadyState::draw(sf::RenderWindow &window) { window.draw(m_text); }
