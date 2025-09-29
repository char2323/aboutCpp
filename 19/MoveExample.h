#pragma once
#include <cstring>
#include <iostream>

class MoveExample {
private:
  int size_;
  int *data_;

public:
  MoveExample(int size) : size_(size), data_(new int[size]) {
    std::cout << "Constructor called.\n";
  }
  MoveExample(const MoveExample &other)
      : size_(other.size_), data_(new int[other.size_]) {
    std::copy(other.data_, other.data_ + size_, data_);
    std::cout << "Copy constructor called.\n";
  }
  MoveExample(MoveExample &&other) noexcept
      : size_(other.size_), data_(other.data_) {
    other.size_ = 0;
    other.data_ = nullptr;
    std::cout << "Move constructor called.\n";
  }
  MoveExample &operator=(const MoveExample &other) {
    if (this == &other)
      return *this;
    delete[] data_;
    size_ = other.size_;
    data_ = new int[size_];
    std::copy(other.data_, other.data_ + size_, data_);
    std::cout << "Copy assignment operator called.\n";
    return *this;
  }
  MoveExample &operator=(MoveExample &&other) {
    if (this == &other)
      return *this;
    delete[] data_;
    size_ = other.size_;
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = 0;
    std::cout << "Move assignment operator called.\n";
    return *this;
  }
  ~MoveExample() {
    delete[] data_;
    std::cout << "Destructor called.\n";
  }
};
