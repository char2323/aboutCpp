#pragma once

#include <iostream>
class Example {
private:
  int data_;

public:
  Example() : data_(0) {
    std::cout << "Default constructor called." << std::endl;
  }
  Example(int data) : data_(data) {
    std::cout << "Parameterized constructor called with data = " << data_
              << std::endl;
  }
  Example(const Example &other) : data_(other.data_) {
    std::cout << "Copy constructor called.\n";
  }
  Example(Example &&other) noexcept : data_(other.data_) {
    other.data_ = 0;
    std::cout << "Move constructor called.\n";
  }
  ~Example() { std::cout << "Destructor called for data = " << data_ << ".\n"; }

  Example &setData(int data) {
    this->data_ = data;
    return *this;
  }
  void printData() const { std::cout << this->data_ << std::endl; }
};
