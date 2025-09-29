#pragma once
#include <cstddef>
#include <cstring>
#include <iostream>

class Mystring {
public:
  Mystring(const char *str = nullptr) {
    if (str) {
      size_ = std::strlen(str);
      data_ = new char[size_ + 1];
      std::strcpy(data_, str);
    } else {
      size_ = 0;
      data_ = new char[1];
      data_[0] = '\0';
    }
    std::cout << "Constructor called.\n";
  }
  Mystring(const Mystring &other) : size_(other.size_) {
    data_ = new char[size_ + 1];
    std::strcpy(data_, other.data_);
    std::cout << "Copy constructor called.\n";
  }
  Mystring &operator=(const Mystring &other) {
    if (this == &other)
      return *this;
    delete[] data_;
    size_ = other.size_;
    data_ = new char[size_ + 1];
    std::strcpy(data_, other.data_);
    std::cout << "Copy assignment operator called.\n";
    return *this;
  }
  ~Mystring() {
    delete[] data_;
    std::cout << "Destructor called.\n";
  }

  inline void print() const { std::cout << data_ << std::endl; }

private:
  char *data_;
  std::size_t size_;
};
