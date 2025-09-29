#include "MemoryPool.h"
#include <iostream>
#include <new>

class MyClass {
public:
  int value_;
  MyClass(int value) : value_(value) {
    std::cout << "MyClass constructor:" << value << std::endl;
  }
  ~MyClass() { std::cout << "MyClass destructor:" << value_ << std::endl; }
};

int main(int argc, char *argv[]) {
  try {
    MemoryPool pool(sizeof(MyClass), 3);
    void *mem1 = pool.allocate();
    void *mem2 = pool.allocate();
    void *mem3 = pool.allocate();

    MyClass *obj1 = new (mem1) MyClass(100);
    MyClass *obj2 = new (mem2) MyClass(200);
    MyClass *obj3 = new (mem3) MyClass(300);

    obj1->~MyClass();
    obj2->~MyClass();
    obj3->~MyClass();

    pool.deallocate(mem1);
    pool.deallocate(mem2);
    pool.deallocate(mem3);
  } catch (const std::bad_alloc &e) {
    std::cerr << "Memory pool allcation error:" << e.what() << std::endl;
    return 1;
  }
  return 0;
}
