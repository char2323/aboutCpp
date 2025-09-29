#include <iostream>
#include <iterator>

int main(int argc, char *argv[]) {
  {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (auto &num : array) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
  {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *beg = std::begin(array);
    int *end = std::end(array);
    for (; beg != end; ++beg) {
      std::cout << *beg << " ";
    }
  }
  return 0;
}
