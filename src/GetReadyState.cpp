#include "GetReadyState.hpp"

#include <SFML/Graphics.hpp>

#include "Helpers.hpp"

GetReadyState::GetReadyState(Game& game) : GameState(game) {
  setText();
  setLogo();
}

void GetReadyState::update(sf::Time delta) {}

void GetReadyState::draw(sf::RenderWindow& window) {
  window.draw(m_text);
  window.draw(m_sprite);
}

void GetReadyState::setText() {
  m_text.setFont(getGame().getFont());
  m_text.setString("Press Space when you're ready...");
  m_text.setCharacterSize(14);
  centerOrigin(m_text);
  m_text.setPosition(240, 240);
}

void GetReadyState::setLogo() {
  m_sprite.setTexture(getGame().getLogo());
  m_sprite.setPosition(50, 50);
}

void GetReadyState::handleKeyboardEvents(sf::Keyboard::Key code) {
  if (code == sf::Keyboard::Escape)
    ;  // Quit game
  if (code == sf::Keyboard::Space)
    getGame().changeGameState(GameState::Playing);
  if (code == sf::Keyboard::R) getGame().changeGameState(GameState::EndGame);
}