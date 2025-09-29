#include "MyHashMap.h"
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

struct Person {
  std::string name;
  int age;
  bool operator==(const Person &other) const {
    return name == other.name && age == other.age;
  }
};

struct PersonHash {
  std::size_t operator()(const Person &p) const {
    return std::hash<std::string>()(p.name) ^ (std::hash<int>()(p.age) << 1);
  }
};

int main() {
  // std::unordered_map<std::string, int> fruit_count;
  // fruit_count["apple"] = 10;
  // fruit_count["banana"] = 20;
  // fruit_count.emplace("orange", 2);
  //
  // std::cout << "Apple count: " << fruit_count["apple"] << std::endl;
  //
  // for (const auto pair : fruit_count) {
  //   std::cout << pair.first << ": " << pair.second << std::endl;
  // }
  //
  // std::unordered_map<Person, std::string, PersonHash> person_map;
  // Person p1{"charmmy", 22};
  // Person p2{"Alice", 19};
  // person_map[p1] = "Engineer";
  // person_map.emplace(p2, "Designer");
  //
  // Person p3{"Alice", 30};
  // std::cout << "Alice's job: " << person_map[p3] << std::endl;
  //
  // std::cout << "charmmy's job: " << person_map[p1] << std::endl;
  //
  // std::cout << "--------------" << std::endl;
  // for (const auto pair : person_map) {
  //   std::cout << pair.first.name << " " << pair.first.age << " " <<
  //   pair.second
  //             << std::endl;
  // }

  UnorderedMap<std::string, int> word_count;

  word_count.insert("hello", 1);
  word_count["world"] = 2;
  word_count["hello"] = word_count["hello"] + 1; // 更新
  word_count["c++"] = 5;
  word_count["iterator"] = 3;

  std::cout << "--- 使用基于范围的 for 循环遍历 Map ---" << std::endl;
  for (const auto &pair : word_count) {
    std::cout << "Key: \"" << pair.first << "\", Value: " << pair.second
              << std::endl;
  }

  std::cout << "\n--- 使用 find 和迭代器 ---" << std::endl;
  auto it = word_count.find("world");
  if (it != word_count.end()) {
    std::cout << "找到了 \"world\", 它的值为 " << it->second << std::endl;

    // 修改值
    it->second = 100;
  }

  std::cout << "修改后 \"world\" 的值为: " << word_count["world"] << std::endl;

  auto not_found_it = word_count.find("java");
  if (not_found_it == word_count.end()) {
    std::cout << "没有找到 \"java\"" << std::endl;
  }

  return 0;
}
