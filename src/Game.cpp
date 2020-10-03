#include "Game.hpp"

#include <iostream>

#include "EndGameState.hpp"
#include "GetReadyState.hpp"
#include "PlayingState.hpp"

Game::Game() : m_window(sf::VideoMode(480, 500), "Rho Tetris") {
  m_window.setMouseCursorVisible(false);
  loadAssets();
  initializeGameStates();
  changeGameState(GameState::GetReady);
}

void Game::initializeGameStates() {
  m_gameStates[GameState::GetReady] = std::make_shared<GetReadyState>(*this);
  m_gameStates[GameState::Playing] = std::make_shared<PlayingState>(*this);
  m_gameStates[GameState::EndGame] = std::make_shared<EndGameState>(*this);
}

void Game::loadAssets() {
  if (!m_font.loadFromFile("assets/font.ttf"))
    throw std::runtime_error("Unable to load the font file");

  if (!m_logo.loadFromFile("assets/logo.png"))
    throw std::runtime_error("Unable to load the logo file");

  if (!m_texture.loadFromFile("assets/texture.png"))
    throw std::runtime_error("Unable to load the texture file");
}

Game::~Game() {}

void Game::run() {
  sf::Clock frameClock;
  while (m_window.isOpen()) {
    sf::Event event;

    while (m_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) m_window.close();

      if (event.type == sf::Event::KeyPressed) {
        m_currentState->handleKeyboardEvents(event.key.code);
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

void Game::exit() { m_window.close(); }
