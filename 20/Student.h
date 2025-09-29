#pragma once
#include "Person.h"
#include <string>

class Student : public Person {
private:
  std::string studentID;

public:
  Student(std::string name, int age, std::string studentID)
      : Person(name, age), studentID(studentID) {}
  void displayInfo() const;
};
