#include "Person.h"
#include <iostream>

void Person::displayInfo() const {
  std::cout << "name is:" << name_ << ", age is:" << age_;
}
