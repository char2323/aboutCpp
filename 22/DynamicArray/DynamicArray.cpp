#include "DynamicArray.h"
#include <stdexcept>

void DynamicArray::resize(size_t new_capacity) {
  int *temp = (int *)realloc(data_, new_capacity * sizeof(int));
  if (temp == nullptr) {
    throw std::bad_alloc();
  }
  data_ = temp;
  capacity_ = new_capacity;
}

void DynamicArray::add(int value) {
  if (size_ == capacity_) {
    resize(capacity_ * 2);
  }
  data_[size_++] = value;
}

int DynamicArray::get(size_t index) const {
  if (index >= size_) {
    throw std::out_of_range("Index out of range.");
  }
  return data_[index];
}
