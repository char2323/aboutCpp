#include "Student.h"
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
  auto *s = new Student();
  std::shared_ptr<Student> shared_student1(s);
  // 等价于:std::shared_ptr<Student> shared_student=std::shared_ptr<Student>(s);
  // 等价于:std::shared_ptr<Student> shared_student(new Student);
  // 等价于:std::shared_ptr<Student>
  // shared_student=std::make_shared<Student>("name",age,"10001");
  std::shared_ptr<Student> shared_student2 = shared_student1;
  std::cout << shared_student1.use_count() << std::endl;
  std::cout << shared_student2.use_count() << std::endl;
  std::shared_ptr<Student> shared_student3;
  shared_student3 = shared_student1;
  std::cout << shared_student3.use_count() << std::endl;

  shared_student3.reset(new Student("Charming", 22, "10002"));
  std::cout << shared_student1.use_count() << std::endl;
  std::cout << shared_student2.use_count() << std::endl;
  std::cout << shared_student3.use_count() << std::endl;

  std::cout << "--------------------------------" << std::endl;

  return 0;
}
