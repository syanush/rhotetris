#include "PlayingState.hpp"

PlayingState::PlayingState(Game& game)
    : GameState(game) {
}

void PlayingState::draw(sf::RenderWindow& window) {
}

void PlayingState::update(sf::Time delta) {}

void PlayingState::handleKeyboardEvents(sf::Keyboard::Key code) {
  if (code == sf::Keyboard::Escape)
    getGame().changeGameState(GameState::GetReady);
  if (code == sf::Keyboard::R) getGame().changeGameState(GameState::EndGame);
}
