#include "Game.hpp"

#include <iostream>

Game::Game() : m_window(sf::VideoMode(480, 500), "Rho Tetris") {
  if (!m_font.loadFromFile("assets/font.ttf"))
    throw std::runtime_error("Unable to load the font file");

  if (!m_logo.loadFromFile("assets/logo.png"))
    throw std::runtime_error("Unable to load the logo file");

  if (!m_texture.loadFromFile("assets/texture.png"))
    throw std::runtime_error("Unable to load the texture file");

  m_gameStates[GameState::Playing] = new PlayingState(this);
  m_gameStates[GameState::GetReady] =
      new GetReadyState(this, m_gameStates[GameState::Playing]);

  changeGameState(GameState::GetReady);
}

Game::~Game() {
  for (GameState *gameState : m_gameStates) delete gameState;
}

void Game::run() {
  sf::Clock frameClock;
  while (m_window.isOpen()) {
    sf::Event event;

    while (m_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) m_window.close();

      if (event.type == sf::Event::KeyPressed) {
      }
    }

    m_currentState->update(frameClock.restart());
    m_window.clear();
    m_currentState->draw(m_window);
    m_window.display();
  }
}

void Game::changeGameState(GameState::State gameState) {
  m_currentState = m_gameStates[gameState];
}

sf::Font &Game::getFont() { return m_font; }

sf::Texture &Game::getLogo() { return m_logo; }

sf::Texture &Game::getTexture() { return m_texture; }