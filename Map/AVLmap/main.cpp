#include "AVLmap.h"
#include <iostream>

int main() {
  AVLMap<int, std::string> myMap;

  std::cout << "Is map empty? " << (myMap.empty() ? "Yes" : "No") << std::endl;

  std::cout << "\nInserting elements..." << std::endl;
  myMap.insert(10, "Apple");
  myMap.insert(20, "Banana");
  myMap.insert(30, "Cherry");
  myMap.insert(40, "Date");
  myMap.insert(50, "Elderberry");
  myMap.insert(25, "Fig");

  std::cout << "Map size: " << myMap.size() << std::endl;
  std::cout << "In-order traversal:" << std::endl;
  myMap.in_order_traversal();

  std::cout << "\nUsing operator[] to access and modify elements:" << std::endl;
  myMap[10] = "Avocado"; // 修改已存在的值
  myMap[60] = "Grape";   // 插入新值
  std::cout << "Value for key 10: " << myMap[10] << std::endl;
  std::cout << "Value for key 60: " << myMap[60] << std::endl;

  std::cout << "\nMap size after using operator[]: " << myMap.size()
            << std::endl;
  std::cout << "In-order traversal:" << std::endl;
  myMap.in_order_traversal();

  std::cout << "\nFinding elements:" << std::endl;
  const std::string *val = myMap.find(20);
  if (val) {
    std::cout << "Found key 20 with value: " << *val << std::endl;
  } else {
    std::cout << "Key 20 not found." << std::endl;
  }

  val = myMap.find(100);
  if (val) {
    std::cout << "Found key 100 with value: " << *val << std::endl;
  } else {
    std::cout << "Key 100 not found." << std::endl;
  }

  std::cout << "\nDeleting elements..." << std::endl;
  myMap.erase(30); // 删除一个中间节点
  std::cout << "Deleted key 30. Map size: " << myMap.size() << std::endl;
  myMap.in_order_traversal();

  myMap.erase(10); // 删除一个节点
  std::cout << "Deleted key 10. Map size: " << myMap.size() << std::endl;
  myMap.in_order_traversal();

  myMap.erase(50); // 删除一个节点
  std::cout << "Deleted key 50. Map size: " << myMap.size() << std::endl;
  myMap.in_order_traversal();

  return 0;
}
