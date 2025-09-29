#include "BSTMap.h"
#include <iostream>

int main() {
  BSTMap<int, std::string> map;

  // 插入键值对
  map.insert(5, "five");
  map.insert(3, "three");
  map.insert(7, "seven");
  map.insert(2, "two");
  map.insert(4, "four");
  map.insert(6, "six");
  map.insert(8, "eight");

  // 遍历（中序遍历，键是有序的）
  std::cout << "遍历 BSTMap (中序):" << std::endl;
  for (auto it = map.begin(); it != map.end(); ++it) {
    auto [key, value] = *it;
    std::cout << key << " : " << value << std::endl;
  }

  std::cout << "-------------------" << std::endl;

  // 使用 contains
  std::cout << "map.contains(4)? " << (map.contains(4) ? "yes" : "no")
            << std::endl;
  std::cout << "map.contains(10)? " << (map.contains(10) ? "yes" : "no")
            << std::endl;

  std::cout << "-------------------" << std::endl;

  // 使用 operator[]
  std::cout << "map[6] = " << map[6] << std::endl;
  map[6] = "six updated"; // 修改值
  std::cout << "map[6] (修改后) = " << map[6] << std::endl;

  // 插入不存在的键会创建默认值
  std::cout << "map[10] (新建) = " << map[10] << std::endl;
  map[10] = "ten";
  std::cout << "map[10] (修改后) = " << map[10] << std::endl;

  std::cout << "-------------------" << std::endl;

  // 删除键
  map.erase(7);
  std::cout << "删除 key=7 后遍历:" << std::endl;
  for (auto it = map.begin(); it != map.end(); ++it) {
    auto [key, value] = *it;
    std::cout << key << " : " << value << std::endl;
  }

  return 0;
}
