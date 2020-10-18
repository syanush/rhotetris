#pragma once

#include <functional>
#include <vector>

#include "IObserver.hpp"

class Observable {
 public:
  void register_observer(IObserver& o) { observers.push_back(o); }

 protected:
  void notify_observers() {
    for (IObserver& o : observers) o.notify();
  }

 private:
  std::vector<std::reference_wrapper<IObserver>> observers;
};
