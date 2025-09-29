#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>

class MyClass {
public:
  MyClass(int val) : value_(val) {
    std::cout << "Constructor called with value: " << value_ << std::endl;
  }
  ~MyClass() {
    std::cout << "Destructor called for value: " << value_ << std::endl;
  }

private:
  int value_;
};

class DynamicArray {
private:
  std::size_t size_;
  int *data_;

public:
  DynamicArray(size_t Initial_size = 1)
      : size_(Initial_size),
        data_((int *)std::malloc(Initial_size * sizeof(int))) {
    if (data_ == nullptr) {
      throw std::bad_alloc();
    }
  }
  ~DynamicArray() { free(data_); }
  void resize(size_t new_size) {
    int *temp = (int *)realloc(data_, new_size * sizeof(int));
    if (temp == nullptr) {
      throw std::bad_alloc();
    }
    data_ = temp;
    size_ = new_size;
  }

  int &operator[](size_t index) { return data_[index]; }

  size_t gerSize() const { return size_; }
};

int main(int argc, char *argv[]) {
  int *p = (int *)malloc(sizeof(int));
  if (p == nullptr) {
    std::cerr << "Memory allocation failed.\n";
    return 1;
  }
  *p = 10;
  std::cout << "Value=" << *p << std::endl;
  free(p);
  std::cout << "--------------------------------\n";

  MyClass *m = new MyClass(10);
  delete m;
  std::cout << "--------------------------------\n";

  int *arr = new int[5];
  for (int i = 0; i < 5; ++i) {
    arr[i] = i * 2;
  }
  for (int i = 0; i < 5; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  delete[] arr;
  std::cout << "--------------------------------\n";

  {
    int size = 3;
    int *arr = (int *)malloc(sizeof(int) * size);
    if (arr == nullptr) {
      std::cerr << "Initial malloc failed.\n";
      return 1;
    }
    for (int i = 0; i < size; ++i) {
      arr[i] = i + 3;
    }
    std::cout << "Initial array:";
    for (int i = 0; i < size; ++i) {
      std::cout << "arr[" << i << "]=" << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------------------\n";
    size = 10;
    int *temp = (int *)realloc(arr, size * sizeof(int));
    if (temp == nullptr) {
      std::cerr << "Initial malloc failed.\n";
      free(arr);
      return 1;
    }
    arr = temp;
    for (int i = 0; i < size; ++i) {
      arr[i] = i * 5;
    }
    std::cout << "Reallocated array:";
    for (int i = 0; i < size; ++i) {
      std::cout << "arr[" << i << "]=" << arr[i] << " ";
    }
    std::cout << std::endl;
    free(arr);
    std::cout << "--------------------------------\n";
  }

  {
    try {
      DynamicArray arr(3);
      for (size_t i = 0; i < arr.gerSize(); ++i) {
        arr[i] = i + 1;
      }
      std::cout << "Initial array:";
      for (size_t i = 0; i < arr.gerSize(); ++i) {
        std::cout << arr[i] << " ";
      }
      std::cout << std::endl;

      arr.resize(5);
      arr[3] = 10;
      arr[4] = 11;
      std::cout << "Resized array:";
      for (size_t i = 0; i < arr.gerSize(); ++i) {
        std::cout << arr[i] << " ";
      }
      std::cout << std::endl;

    } catch (const std::bad_alloc &e) {
      std::cerr << "Memory allocation error:" << e.what() << std::endl;
      return 1;
    }
  }
  return 0;
}
