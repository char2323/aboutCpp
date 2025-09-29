#include "Deque.h"
#include <deque>
#include <iostream>

int main() {
  std::deque<std::string> dq;
  dq.push_back("Hello");
  dq.push_back("World");
  for (auto it = dq.begin(); it != dq.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  dq.push_front("C++,");
  dq.push_front("Welcome");
  for (auto it = dq.begin(); it != dq.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  dq.pop_front();
  for (auto it = dq.begin(); it != dq.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  dq.pop_back();
  for (auto it = dq.begin(); it != dq.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "-----------------------------------------------\n";
  {
    Deque<std::string> dq;
    dq.push_back("Hello");
    dq.push_back("World");
    for (auto it = dq.begin(); it != dq.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    dq.push_front("C++,");
    dq.push_front("Welcome");
    for (auto it = dq.begin(); it != dq.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    dq.pop_front();
    for (auto it = dq.begin(); it != dq.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    dq.pop_back();
    for (auto it = dq.begin(); it != dq.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
