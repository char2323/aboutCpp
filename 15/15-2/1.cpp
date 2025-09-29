#include <cstddef>
#include <iostream>

// 编写一个C++程序，输入一个3x3的矩阵，计算其转置矩阵，并输出结果。

int main() {
  const int SIZE = 3;
  int matrix[SIZE][SIZE];
  int transpose[SIZE][SIZE];

  // 输入原始矩阵
  std::cout << "请输入一个3x3矩阵的元素（共9个整数）:" << std::endl;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      // 在此输入matrix[i][j]
      std::cin >> matrix[i][j];
    }
  }

  // 计算转置矩阵
  // 在此实现转置逻辑
  int temp = 0;
  for (size_t row = 0; row != SIZE; ++row) {
    for (size_t col = 0; col != SIZE; ++col) {
      transpose[col][row] = matrix[row][col];
    }
  }

  // 输出转置后的矩阵
  std::cout << "矩阵的转置为:" << std::endl;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      // 在此输出transpose[i][j]
      std::cout << transpose[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
