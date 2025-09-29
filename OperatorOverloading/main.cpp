#include "Complex.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Complex c1(3.5, 1.2);
  Complex c2(1.3, 2.1);
  std::cout << c1 << std::endl;
  std::cout << c2 << std::endl;
  Complex c3 = c1 + c2;
  std::cout << c3 << std::endl;
  Complex c4 = c1 - c2;
  std::cout << c4 << std::endl;
  Complex c5 = c1 * c2;
  std::cout << c5 << std::endl;
  c5 = c4;
  std::cout << c5 << std::endl;
  auto equal = (c4 == c5);
  std::cout << equal << std::endl;

  return 0;
}
