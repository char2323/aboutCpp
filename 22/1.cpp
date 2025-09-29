#include <cstdlib>
#include <iostream>
#include <new>
#include <stdexcept>

class DynamicArray {
private:
  void resize() {
    capacity_ *= 2;
    int *newData = (int *)realloc(data, capacity_ * sizeof(int));
    if (!newData) {
      throw std::runtime_error("Memory reallocation failed");
    }
    data = newData;
  }
  int *data;
  int capacity_;
  int size;

public:
  DynamicArray()
      : capacity_(2), size(0), data((int *)malloc(capacity_ * sizeof(int))) {
    if (!data) {
      throw std::runtime_error("Memory allocation failed");
    }
  }
  ~DynamicArray() { free(data); }
  void add(int value) {
    if (size == capacity_) {
      resize();
    }
    data[size++] = value;
  }
  int get(int index) const {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }
  int getSize() const { return size; }
};

int main() {
  try {
    DynamicArray arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);
    for (int i = 0; i < arr.getSize(); ++i) {
      std::cout << arr.get(i) << " ";
    }
    std::cout << std::endl;

  } catch (const std::bad_alloc &e) {
    std::cerr << "Memory allocation error:" << e.what() << std::endl;
    return 1;
  } catch (const std::out_of_range &e) {
    std::cerr << "array access error:" << e.what() << std::endl;
    return 1;
  }
  return 0;
}
