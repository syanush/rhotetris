#pragma once

#include <functional>
#include <vector>

#include "IGameOverEventHandler.hpp"

class GameOverEvent {
 public:
  void addGameOverEventHandler(IGameOverEventHandler& o) {
    m_gameOverEventHandlers.push_back(o);
  }

 protected:
  void handleGameOverEvent() {
    for (IGameOverEventHandler& o : m_gameOverEventHandlers) {
      o.handleGameOverEvent();
    }
  }

 private:
  std::vector<std::reference_wrapper<IGameOverEventHandler>>
      m_gameOverEventHandlers;
};
