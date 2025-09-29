#pragma once
#include <cstring>
#include <iostream>
// 创建一个简单的MyString类，支持拷贝构造，默认构造，有参构造，支持输出和比较等
class Mystring {
public:
  Mystring() : data_(nullptr) {}
  Mystring(char *str) {
    if (str) {
      data_ = new char[strlen(str) + 1];
      strcpy(data_, str);
    } else {
      data_ = nullptr;
    }
  }
  Mystring(const Mystring &other) {
    if (other.data_) {
      data_ = new char[strlen(other.data_) + 1];
      strcpy(data_, other.data_);
    } else {
      data_ = nullptr;
    }
  }
  Mystring &operator=(const Mystring &other) {
    if (this == &other) {
      return *this;
    } else {
      delete[] data_;
      if (other.data_) {
        data_ = new char[strlen(other.data_) + 1];
        strcpy(data_, other.data_);
      } else {
        data_ = nullptr;
      }
    }
    return *this;
  }

  bool operator==(const Mystring &other) const {
    if (data_ == nullptr && other.data_ == nullptr)
      return true;
    if (data_ == nullptr || other.data_ == nullptr)
      return false;
    return strcmp(data_, other.data_) == 0;
  }

  friend std::ostream &operator<<(std::ostream &os, const Mystring &str);

  ~Mystring() { delete[] data_; }

private:
  char *data_;
};
