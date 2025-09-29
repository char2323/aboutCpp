#include <iostream>
#include <stdexcept>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> vec1;
  std::vector<int> vec2(5, 10);
  std::vector<int> vec3 = {1, 2, 3, 4, 5};
  std::vector<int> vec4(vec3);
  std::vector<int> vec5(std::move(vec4));

  std::cout << "vec2:";
  for (int temp : vec2) {
    std::cout << temp << " ";
  }
  std::cout << std::endl;

  std::cout << vec2.size() << std::endl;
  std::cout << vec2.capacity() << std::endl;
  vec2.push_back(100);
  std::cout << vec2.size() << std::endl;
  std::cout << vec2.capacity() << std::endl;

  std::cout << vec3.size() << std::endl;
  std::cout << vec3.capacity() << std::endl;

  std::cout << "-----------------------------" << std::endl;

  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  std::cout << "after push_back:" << std::endl;
  for (int temp : vec) {
    std::cout << temp << " ";
  }
  std::cout << std::endl;

  std::cout << "after pop_back:" << std::endl;
  vec.pop_back();
  for (int temp : vec) {
    std::cout << temp << " ";
  }
  std::cout << std::endl;

  std::cout << "after insert:" << std::endl;
  vec.insert(vec.begin() + 1, 2, 25);
  for (int temp : vec) {
    std::cout << temp << " ";
  }
  std::cout << std::endl;

  std::cout << "after erase:" << std::endl;
  vec.erase(vec.begin() + 2);
  for (int temp : vec) {
    std::cout << temp << " ";
  }
  std::cout << std::endl;

  vec.clear();
  std::cout << "after clear(),size:" << vec.size() << std::endl;
  std::cout << "after clear(),capacity:" << vec.capacity() << std::endl;
  std::cout << std::endl;
  // 立即回收机制
  {
    std::vector<int> empty_vec;
    empty_vec.swap(vec);
    std::cout << "after swap(),vec's capacity:" << vec.capacity() << std::endl;
    std::cout << "after swap(),empty_vec's capacity:" << empty_vec.capacity()
              << std::endl;
    std::cout << std::endl;
  }

  std::vector<std::string> fruits = {"apple", "banana", "orange"};
  std::cout << "the first fruit is :" << fruits[0] << std::endl;
  std::cout << "the second fruit is :" << fruits.at(1) << std::endl;

  try {
    std::cout << "invalid fruits:" << fruits.at(100) << std::endl;
  } catch (std::out_of_range &e) {
    std::cerr << "Exception:" << e.what() << std::endl;
  }

  for (auto it = fruits.begin(); it != fruits.end(); ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << std::endl;

  auto iter = fruits.end() - 1;
  *iter = "lemon";
  std::cout << fruits[2] << std::endl;

  return 0;
}
