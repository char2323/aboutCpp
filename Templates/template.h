#pragma once
#include <cstddef>
#include <iostream>
#include <memory>

template <typename T> T maxValue(T a, T b) { return a > b ? a : b; }

template <typename T, typename U> class Pair {
public:
  T first;
  U second;
  Pair(T a, U b) : first(a), second(b) {}
  void print() const { std::cout << first << " " << second << std::endl; }
};

template <typename T, std::size_t N> class FixedArray {
public:
  T data[N];
  T &operator[](std::size_t index) { return data[index]; }
  void print() const {
    for (size_t i = 0; i < N; ++i) {
      std::cout << data[i] << " ";
    }
    std::cout << std::endl;
  }
};

template <template <typename, typename> class Container, typename T>
class ContainerPrinter {
public:
  void Printer(const Container<T, std::allocator<T>> &c) {
    for (const auto &elem : c) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
};

template <typename T> class Printer {
public:
  void printer(const T &t) {
    std::cout << "general printer:" << t << std::endl;
  }
};

// 特化
// 全特化
template <> class Printer<std::string> {
public:
  void printer(std::string s) {
    std::cout << "string printer:" << s << std::endl;
  }
};

// 偏特化
template <typename T, typename U> class Pair<T, U *> {
public:
  T first;
  U *second;
  Pair(T a, U *b) : first(a), second(b) {}
  void print() const {
    std::cout << "Pair:" << first << " " << *second << std::endl;
  }
};

template <typename T> void printValue(const T &obj) {
  std::cout << "general printValue: " << obj << std::endl;
}

template <> inline void printValue<std::string>(const std::string &value) {
  std::cout << "Specialized print for string: " << value << std::endl;
}

template <> void printValue<int *>(int *const &ptr) {
  std::cout << "Pointer print: " << *ptr << std::endl;
}

void printAll() { std::cout << std::endl; }

template <typename T, typename... Args>
void printAll(const T &first, const Args &...args) {
  std::cout << first << " ";
  printAll(args...);
}

template <typename... Args> void coutAll(const Args &...args) {
  ((std::cout << args << " "), ...);
}

template <typename... Args>
auto sumAll(Args... args) -> decltype((args + ...)) {
  return (args + ...);
}

template <typename... Args> bool allNot(const Args &...args) {
  return (!args && ...); // !a && !b && !c && ...
}

template <typename... Args>
auto sumLeftFold(const Args &...args) -> decltype((args + ...)) {
  return (args + ...);
}

template <typename... Args>
auto multiRightFold(const Args &...args) -> decltype((args + ...)) {
  return (... * args); // a*(b*(c*d))
}

template <typename... Args> void print_all(const Args &...args) {
  (std::cout << ... << args) << std::endl;
}

struct MyPoint {
  int _x;
  int _y;
  MyPoint(int x, int y) : _x(x), _y(y) {}
  MyPoint operator+(const MyPoint &other) const {
    return MyPoint(_x + other._x, _y + other._y);
  }
};

template <typename... Args>
auto sumPoints(const Args &...args) -> decltype((args + ...)) {
  return (args + ...);
}
