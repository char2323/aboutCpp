#include "Person.h"
#include "Student.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Student s1 = Student("charmmy", 21, "1001");
  s1.displayInfo();
  return 0;
}
