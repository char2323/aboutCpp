#include <functional>
#include <iostream>
#include <vector>

using Callback = std::function<void(int)>;

class EventSystem {
private:
  std::vector<Callback> callbacks;

public:
  void registerCallback(const Callback &cb) { callbacks.push_back(cb); }

  void triggerEvent(int data) {
    std::cout << "Event triggered with data: " << data
              << ". Executing callbcaks..." << std::endl;
    for (auto &cb : callbacks) {
      cb(data);
    }
  }
};

void onEvent(int data) {
  std::cout << "Function callback received data:" << data << std::endl;
}

int main() {
  EventSystem enventSystem;
  enventSystem.registerCallback(onEvent);
  enventSystem.registerCallback([](int x) {
    std::cout << "Lambda callback received: " << x * 2 << std::endl;
  });

  int multiplier = 5;
  enventSystem.registerCallback([multiplier](int x) {
    std::cout << "Lambda with capture received: " << x * multiplier
              << std::endl;
  });

  enventSystem.triggerEvent(10);
}
