#pragma once
#include <string>
class Person {
private:
  std::string name_;
  int age_;

public:
  Person(std::string name, int age) : name_(name), age_(age) {}
  virtual void displayInfo() const;
};
