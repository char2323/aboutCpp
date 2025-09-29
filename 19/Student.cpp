#include "Student.h"

void Student::printInfo(const Student &s) const {
  std::cout << "Name: " << s.getName() << std::endl;
  std::cout << "Id: " << s.getId() << std::endl;
  std::cout << "Marks: " << s.getMarks() << std::endl;
}
