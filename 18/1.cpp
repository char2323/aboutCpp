#include <algorithm>
#include <iostream>
#include <vector>

void printvec(const std::vector<int> &vec) {
  for (auto x : vec) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
  // 使用Lambda表达式打印元素;
  std::for_each(numbers.begin(), numbers.end(),
                [](int x) { std::cout << x << " "; });
  std::cout << std::endl;
  // 使用Lambda表达式计算总和;
  int sum = 0;
  std::for_each(numbers.begin(), numbers.end(), [&sum](int x) { sum += x; });
  std::cout << "numbers sum = " << sum << std::endl;

  // 使用Lambda表达式排序;
  std::vector<int> data = {3, 4, 6, 8, 2, 5, 6};
  std::cout << "data before sort: ";
  printvec(data);
  std::sort(data.begin(), data.end(), [](int a, int b) { return a > b; });
  std::cout << "data after sort: ";
  printvec(data);

  return 0;
}
