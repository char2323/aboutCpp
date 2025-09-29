#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<std::string> fruits = {"apple", "banana", "grape", "pineapple",
                                     "strawberry"};
  // 使用Lambda表达式按照字符串长度进行排序
  std::sort(fruits.begin(), fruits.end(),
            [](const std::string &a, const std::string &b) {
              return a.size() < b.size();
            });

  std::cout << "Fruits sorted by length: " << std::endl;
  for (const auto &fruit : fruits) {
    std::cout << fruit << " ";
  }
  std::cout << std::endl;

  return 0;
}
