#include "MyMap.h"
#include <functional>
#include <iostream>
#include <map>
#include <string>

class Person {
public:
  std::string name;
  int age;
  Person(int a, std::string n) : name(n), age(a) {}
  bool operator<(const Person &other) const { return age < other.age; }
};

struct comparePerson {
  bool operator()(const Person &a, const Person &b) const {
    return a.age < b.age;
  }
};

int main() {
  // // Create a map to store integer keys and string values
  // std::map<int, std::string> myMap;
  //
  // // Insert key-value pairs into the map
  // myMap[1] = "One";
  // myMap[2] = "Two";
  // myMap[3] = "Three";
  //
  // // Access and print values using their keys
  // std::cout << "Key 1: " << myMap[1] << std::endl;
  // std::cout << "Key 2: " << myMap[2] << std::endl;
  // std::cout << "Key 3: " << myMap[3] << std::endl;
  //
  // myMap.insert(std::pair<int, std::string>(4, "Four"));
  // myMap.insert(std::make_pair(5, "Five"));
  // myMap.insert({6, "Six"});
  //
  // // Iterate through the map and print all key-value pairs
  // std::cout << "All key-value pairs in the map:" << std::endl;
  // for (const auto &pair : myMap) {
  //   std::cout << "Key: " << pair.first << ", Value: " << pair.second
  //             << std::endl;
  // }
  //
  // // for (auto it = myMap.begin(); it != myMap.end(); ++it) {
  // //   std::cout << "Key: " << it->first << ", Value: " << it->second <<
  // //   std::endl;
  // // }
  //
  // std::function<bool(const Person &, const Person &)> comp =
  //     [](const Person &a, const Person &b) { return a.age < b.age; };
  //
  // std::map<Person, int, std::function<bool(const Person &, const Person &)>>
  //     PersonMap(comp);
  // PersonMap[Person(25, "Alice")] = 1;
  // PersonMap[Person(30, "Bob")] = 2;
  // PersonMap[Person(22, "Charlie")] = 3;
  // for (const auto &pair : PersonMap) {
  //   std::cout << "Person: " << pair.first.name << ", Age: " << pair.first.age
  //             << ", Value: " << pair.second << std::endl;
  // }
  // Person p1(21, "Charmmy");
  // PersonMap.insert(std::make_pair(p1, 4));
  // for (const auto &pair : PersonMap) {
  //   std::cout << "Person: " << pair.first.name << ", Age: " << pair.first.age
  //             << ", Value: " << pair.second << std::endl;
  // }
  //

  BSTMap<int, std::string> myMap;
  return 0;
}
