#include "SimpleSharedPtr.h"
#include "Student.h"
#include <iostream>

void change_int_ptr(int *p_int) { *p_int = 10; }

int main(int argc, char *argv[]) {
  // int *p_int = new int(5);
  // std::cout << *p_int << std::endl;
  // change_int_ptr(p_int);
  // std::cout << *p_int << std::endl;
  // delete p_int;

  std::cout << "Creating default constructed shared_ptr..." << std::endl;
  SimpleSharePtr<Student> p1;
  std::cout << p1.use_count() << std::endl;
  std::cout << "Creating shared_ptr with resource..." << std::endl;
  SimpleSharePtr<Student> p2(new Student("Ray", 20, "10001"));
  std::cout << p2.use_count() << std::endl;
  std::cout << "Copying ptr2 to ptr3..." << std::endl;
  SimpleSharePtr<Student> p3(p2);
  std::cout << p3.use_count() << std::endl;
  std::cout << p2.use_count() << std::endl;
  p1 = p3;
  std::cout << p1.use_count() << std::endl;
  std::cout << p2.use_count() << std::endl;
  std::cout << p3.use_count() << std::endl;

  p2.reset(new Student("Ming", 22, "10002"));
  std::cout << "-------------------------" << std::endl;
  std::cout << p1.use_count() << std::endl;
  std::cout << p2.use_count() << std::endl;
  std::cout << p3.use_count() << std::endl;
  return 0;
}
