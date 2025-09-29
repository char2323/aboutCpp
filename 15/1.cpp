#include <cstddef>
#include <iostream>

int main(int argc, char *argv[]) {
  {
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];
    for (size_t i = 0; i != rowCnt; ++i) {
      for (size_t j = 0; j != colCnt; ++j) {
        ia[i][j] = i * colCnt + j;
      }
    }

    int ib[rowCnt][colCnt];
    size_t cnt = 0;
    for (auto &row : ib) {
      for (auto &col : row) {
        col = cnt++;
      }
    }

    for (auto &row : ia) {
      for (auto &col : row) {
        std::cout << col << " ";
      }
      std::cout << std::endl;
    }
    for (auto &row : ib) {
      for (auto &col : row) {
        std::cout << col << " ";
      }
      std::cout << std::endl;
    }
  }
  {
    // int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int ia[3][4];
    int cnt = 0;
    for (auto p = ia; p != ia + 3; ++p) {
      for (auto q = *p; q != *p + 4; ++q) {
        *q = ++cnt;
      }
    }
    for (auto p = ia; p != ia + 3; ++p) {
      for (auto q = *p; q != *p + 4; ++q) {
        std::cout << *q << " ";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
