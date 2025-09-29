#include <cstddef>
#include <iostream>

// 编写一个C++程序，输入两个2x3的矩阵，计算它们的和，并输出结果矩阵。
constexpr int ROW = 2;
constexpr int COL = 3;
int a[ROW][COL];
int b[ROW][COL];

void getdata() {
  std::cout << "请输入矩阵a的数据(2*3):" << std::endl;
  for (auto &row : a) {
    for (auto &col : row) {
      std::cin >> col;
    }
  }
  std::cout << "请输入矩阵b的数据(2*3):" << std::endl;
  for (auto &row : b) {
    for (auto &col : row) {
      std::cin >> col;
    }
  }
}
void printmatrix(int (&matrix)[ROW][COL]) {
  for (auto &row : matrix) {
    for (auto &col : row) {
      std::cout << col << " ";
    }
    std::cout << std::endl;
  }
}
void plusmatrix(const int (&matrix1)[ROW][COL],
                const int (&matrix2)[ROW][COL]) {
  int res[ROW][COL];
  for (size_t row = 0; row != ROW; ++row) {
    for (size_t col = 0; col != COL; ++col) {
      res[row][col] = matrix1[row][col] + matrix2[row][col];
    }
  }
  printmatrix(res);
}

int main(int argc, char *argv[]) {
  getdata();
  // printmatrix(a);
  // printmatrix(b);
  plusmatrix(a, b);

  return 0;
}
