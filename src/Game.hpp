#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <memory>

#include "GameState.hpp"

namespace RhoTetris {

class Game {
 public:
  Game();
  ~Game();

  void run();

  sf::Font &getFont();
  sf::Texture &getLogo();
  sf::Texture &getTexture();

  void changeGameState(GameState::State gameState);
  void exit();

 private:
  sf::RenderWindow m_window;
  std::shared_ptr<GameState> m_currentState;
  std::array<std::shared_ptr<GameState>, GameState::Count> m_gameStates;

  sf::Font m_font;
  sf::Texture m_logo;
  sf::Texture m_texture;

  void loadAssets();

  void initializeGameStates();
};

}  // namespace RhoTetris
