#include "GameState.hpp"

#include "Game.hpp"

template <typename T>
void centerOrigin(T &drawable) {
  sf::FloatRect bound = drawable.getLocalBounds();
  drawable.setOrigin(bound.width / 2, bound.height / 2);
}

GameState::GameState(Game *game) : m_game(game) {}

GetReadyState::GetReadyState(Game *game, GameState *playingState)
    : GameState(game) {
  m_text.setFont(game->getFont());
  m_text.setString("Press Start when you're ready...");
  m_text.setCharacterSize(14);

  centerOrigin(m_text);
  m_text.setPosition(240, 240);
}

PlayingState::PlayingState(Game *game) : GameState(game), m_score(0) {
  m_scene.create(480, 480);
}

PlayingState::~PlayingState() {}

Game *GameState::getGame() const { return m_game; }

void GetReadyState::update(sf::Time delta) {}

void GetReadyState::draw(sf::RenderWindow &window) { window.draw(m_text); }

void PlayingState::update(sf::Time delta) {}

void PlayingState::draw(sf::RenderWindow &window) {
  m_scene.clear();

  m_scene.display();

  window.draw(sf::Sprite(m_scene.getTexture()));
}
