#include <iostream>

int main() {
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= i; ++j) {
      std::cout << i << " * " << j << " = " << i * j << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
