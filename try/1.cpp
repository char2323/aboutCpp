#include <iostream>

int main() {
  // 遍历行，从1到9
  for (int i = 1; i <= 9; ++i) {
    // 遍历列，从1到当前行数i
    for (int j = 1; j <= i; ++j) {
      // 打印乘法表达式
      std::cout << j << "x" << i << "=" << i * j << "\t";
    }
    // 每行打印完后换行
    std::cout << std::endl;
  }

  return 0;
}
