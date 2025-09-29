#pragma once
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>

class DynamicArray {
private:
  size_t capacity_;
  int *data_;
  std::size_t size_;
  void resize(size_t new_capacity);

public:
  DynamicArray()
      : capacity_(2), size_(0), data_((int *)malloc(capacity_ * sizeof(int))) {
    if (data_ == nullptr) {
      throw std::bad_alloc();
    }
  }
  ~DynamicArray() { free(data_); }
  void add(int value);
  int get(size_t index) const;
  inline size_t getSize() const { return size_; }
};
