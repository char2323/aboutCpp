#include "Example.h"
#include "MoveExample.h"
#include "Mystring.h"
#include "Point.h"
#include "Student.h"
#include <iostream>

int main() {
  // Student s1(1, "John Doe", 90.5);
  // s1.printInfo(s1);
  // std::cout << "Student 1 Info:" << std::endl;
  // std::cout << "Name: " << s1.getName() << std::endl;
  // std::cout << "Id: " << s1.getId() << std::endl;
  // std::cout << "Marks: " << s1.getMarks() << std::endl;
  // std::cout << "------------------------" << std::endl;
  // Example ex1;
  // Example ex2(40);
  // Example ex3 = ex2;
  // Example ex4 = std::move(ex3);
  // ex2.printData();
  // ex2.setData(100).printData();
  //
  // std::cout << "--------------------------" << std::endl;
  // Mystring str1("hello");
  // Mystring str2 = str1;
  // Mystring str3;
  // str3 = str1;
  //
  // str1.print();
  // str2.print();
  // str3.print();

  std::cout << "--------------------------" << std::endl;

  MoveExample m1(10);
  MoveExample m2 = m1;
  MoveExample m3(m1);
  MoveExample m4 = MoveExample(20);
  MoveExample m5(MoveExample(30));

  MoveExample m6(40);
  m6 = m4;
  m4 = MoveExample(50);

  std::cout << "--------------------------" << std::endl;

  Point p1(1.5, 2.5);
  Point p2(3.0, 4.0);

  Point p3 = p1 + p2;
  p3.print(); // 输出： (4.5, 6.5)

  Point p4 = p2 - p1;
  p4.print(); // 输出： (1.5, 1.5)

  std::cout << p4;
  return 0;
}
