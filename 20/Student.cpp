#include "Student.h"
#include <iostream>
void Student::displayInfo() const {
  Person::displayInfo();
  std::cout << ", studentID is:" << studentID << std::endl;
}
