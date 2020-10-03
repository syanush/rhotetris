#include "PlayingState.hpp"

PlayingState::PlayingState(Game *game) : GameState(game), m_score(0) {
  m_scene.create(480, 480);
}

PlayingState::~PlayingState() {}

void PlayingState::update(sf::Time delta) {}

void PlayingState::draw(sf::RenderWindow &window) {
  m_scene.clear();
  m_scene.display();
  window.draw(sf::Sprite(m_scene.getTexture()));
}
