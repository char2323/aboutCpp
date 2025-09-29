#include <iostream>

// 使用位运算符，交换两个整数变量的值而不使用第三个变量。

int main(int argc, char *argv[]) {
  int x = 10;
  int y = 2;
  std::cout << "Before swap:x=" << x << ",y=" << y << std::endl;
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
  std::cout << "After swap:x=" << x << ",y=" << y << std::endl;
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i = 0; i < 10; i++) {
    a[i] *= 2;
  }
  return 0;
}
