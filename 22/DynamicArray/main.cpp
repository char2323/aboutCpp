#include "DynamicArray.h"
#include <cstddef>
#include <iostream>
#include <new>
#include <stdexcept>

int main(int argc, char *argv[]) {
  try {
    DynamicArray arr;
    arr.add(10);
    arr.add(10);
    arr.add(30);
    std::cout << "Dynamic Array Contents:" << std::endl;
    for (size_t i = 0; i < arr.getSize(); ++i) {
      std::cout << arr.get(i) << " ";
    }
    std::cout << std::endl;
  } catch (const std::bad_alloc &e) {
    std::cerr << "Memory allocation error:" << e.what() << std::endl;
    return 1;
  } catch (const std::out_of_range &e) {
    std::cerr << "Array access error:" << e.what() << std::endl;
    return 1;
  }
  return 0;
}
