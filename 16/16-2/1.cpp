#include <iostream>

// 编写一个函数，接受一个整数指针，使用解引用运算符修改其值为原值的平方。

void square(int *ptr) { *ptr = (*ptr) * (*ptr); }

int main(int argc, char *argv[]) {
  int num = 10;
  std::cout << "berore:" << num << std::endl;
  square(&num);
  std::cout << "after:" << num << std::endl;
  return 0;
}
