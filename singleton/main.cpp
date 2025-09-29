#include "Singleton.h"
#include <ios>
#include <iostream>
#include <mutex>
#include <thread>

int main() {

  // std::cout << std::boolalpha;
  // std::cout << "s1 addr is: " << &Single2::GetInst() << std::endl;
  // std::cout << "s2 addr is: " << &Single2::GetInst() << std::endl;

  std::mutex mtx;
  // std::thread t1([&]() {
  //   Single2::GetInst();
  //   mtx.lock();
  //   std::cout << "s1 addr is:" << &Single2::GetInst() << std::endl;
  //   mtx.unlock();
  // });
  //
  // std::thread t2([&]() {
  //   Single2::GetInst();
  //   mtx.lock();
  //   std::cout << "s2 addr is:" << &Single2::GetInst() << std::endl;
  //   mtx.unlock();
  // });

  // 利用RAII思想，cpp11以后用lock_guard()实现
  // std::thread t1([&]() {
  //   Single2::GetInst();
  //   std::lock_guard<std::mutex> lock(mtx);
  //   std::cout << "s2 addr is: " << &Single2::GetInst() << std::endl;
  // });
  //
  // std::thread t2([&]() {
  //   Single2::GetInst();
  //   std::lock_guard<std::mutex> lock(mtx);
  //   std::cout << "s2 addr is: " << &Single2::GetInst() << std::endl;
  // });

  // 饿汉式
  // std::thread t1([&]() {
  //   SingleHungry::GetInst();
  //   std::lock_guard<std::mutex> lock(mtx);
  //   std::cout << "s1 addr is: " << SingleHungry::GetInst() << std::endl;
  // });
  //
  // std::thread t2([&]() {
  //   SingleHungry::GetInst();
  //   std::lock_guard<std::mutex> lock(mtx);
  //   std::cout << "s2 addr is: " << SingleHungry::GetInst() << std::endl;
  // });

  // 懒汉式
  // std::thread t1([&]() {
  //   SinglePointer::GetInst();
  //   std::lock_guard<std::mutex> lock(mtx);
  //   std::cout << "s1 addr is: " << SinglePointer::GetInst() << std::endl;
  // });
  //
  // std::thread t2([&]() {
  //   SinglePointer::GetInst();
  //   std::lock_guard<std::mutex> lock(mtx);
  //   std::cout << "s2 addr is: " << SinglePointer::GetInst() << std::endl;
  // });
  //
  std::thread t1([&]() {
    SingleOnceFlag::GetInst();
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "s1 addr is: " << SingleOnceFlag::GetInst() << std::endl;
  });

  std::thread t2([&]() {
    SingleOnceFlag::GetInst();
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "s2 addr is: " << SingleOnceFlag::GetInst() << std::endl;
  });
  t1.join();
  t2.join();
  return 0;
}
