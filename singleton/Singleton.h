#pragma once
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

// c++11以后，是线程安全的
class Single2 {
private:
  Single2() {}
  Single2(const Single2 &) = delete;
  Single2 &operator=(const Single2 &) = delete;

public:
  ~Single2() { std::cout << "Single2 destructed." << std::endl; }

  static Single2 &GetInst() {
    static Single2 single;
    return single;
  }
};

class SingleHungry {
private:
  SingleHungry() {}
  SingleHungry(const SingleHungry &) = delete;
  SingleHungry &operator=(const SingleHungry &) = delete;
  static SingleHungry *single; // 静态成员要在非内联文件初始化
  // 这里不能正确析构，所以用智能指针比较好
public:
  ~SingleHungry() { std::cout << "SingleHungry destructed." << std::endl; }
  static SingleHungry *GetInst() {
    if (!single) {
      single = new SingleHungry();
    }
    return single;
  }
};

class SinglePointer {
private:
  SinglePointer() {}
  SinglePointer(const SinglePointer &) = delete;
  SinglePointer &operator=(const SinglePointer &) = delete;

  static SinglePointer *single;
  static std::mutex s_mutex;

public:
  ~SinglePointer() { std::cout << "SinglePointer destructed." << std::endl; }
  // static SinglePointer *GetInst() {
  //   std::lock_guard<std::mutex> lock(s_mutex);
  //   if (!single) {
  //     single = new SinglePointer();
  //   }
  //   return single;
  // }
  static SinglePointer *GetInst() {
    if (single) // 双重锁检测：带有风险，线程不安全
      return single;
    s_mutex.lock();
    if (single) {
      s_mutex.unlock();
      return single;
    }
    single = new SinglePointer();
    s_mutex.unlock();
    return single;
  }
};

class SingleOnceFlag {
public:
  ~SingleOnceFlag() { std::cout << "SingleOnceFlag destructed." << std::endl; }
  static std::shared_ptr<SingleOnceFlag> GetInst() {
    static std::once_flag flag; // 线程安全
    std::call_once(flag, []() {
      _instance = std::shared_ptr<SingleOnceFlag>(new SingleOnceFlag());
      // std::cout << "SingleOnceFlag constructed, _instance is: " << _instance
      //           << std::endl;
    });
    return _instance;
  }

private:
  SingleOnceFlag() = default;
  SingleOnceFlag(const SingleOnceFlag &) = delete;
  SingleOnceFlag &operator=(const SingleOnceFlag &) = delete;
  // static SingleOnceFlag *_instance;
  static std::shared_ptr<SingleOnceFlag> _instance;
};
