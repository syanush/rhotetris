#include "PlayingState.hpp"

PlayingState::PlayingState(Game& game) : GameState(game), m_score(0) {
  m_scene.create(480, 480);
  m_picture.setTexture(getGame().getTexture());
}

PlayingState::~PlayingState() {}

void PlayingState::update(sf::Time delta) {}

void PlayingState::draw(sf::RenderWindow& window) {
  m_scene.clear();
  m_scene.display();
  window.draw(sf::Sprite(m_scene.getTexture()));
  window.draw(m_picture);
}

void PlayingState::handleKeyboardEvents(sf::Keyboard::Key code) {
  if (code == sf::Keyboard::Escape)
    getGame().changeGameState(GameState::GetReady);
  if (code == sf::Keyboard::R) getGame().changeGameState(GameState::EndGame);
}
