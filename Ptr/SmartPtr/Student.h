#pragma once
#include "Person.h"
#include <string>

class Student : public Person {
private:
  std::string studentID;

public:
  Student() : Student("charmmy", 22, "10001") {}
  Student(std::string name, int age, std::string studentID)
      : Person(name, age), studentID(studentID) {}
  ~Student() = default;
  void displayInfo() const;
};
