#pragma once
#include <iostream>

template <typename T> class Deque {
private:
  T *buffer;
  size_t capacity;
  size_t count;
  size_t front_index;
  size_t back_index;

public:
  Deque(size_t initial_capacity = 10)
      : capacity(initial_capacity), count(0), front_index(0), back_index(0) {
    buffer = new T[capacity];
  }

  ~Deque() { delete[] buffer; }

  bool empty() const { return count == 0; }

  size_t size() const { return count; }

  void resize(size_t new_capacity) {
    T *new_buffer = new T[new_capacity];
    for (size_t i = 0; i < count; ++i) {
      new_buffer[i] = buffer[(front_index + i) % capacity];
    }
    front_index = 0;
    back_index = count % new_capacity;
    capacity = new_capacity;
    delete[] buffer;
    buffer = new_buffer;
  }

  void push_front(const T &value) {
    if (count == capacity) {
      resize(capacity * 2);
    }
    front_index = (front_index + capacity - 1) % capacity;
    // 等价于： (front_index==0)?front_index=capacity-1;front_index--;
    // 等价于：front_index=(front_index==0)?capacity-1:front_index-1;
    buffer[front_index] = value;
    ++count;
  }

  void push_back(const T &value) {
    if (count == capacity) {
      resize(capacity * 2);
    }
    buffer[back_index] = value;
    back_index = (back_index + 1) % capacity;
    ++count;
  }

  void pop_front() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    front_index = (front_index + 1) % capacity;
    --count;
    if (count > 0 && count == capacity / 4) {
      resize(capacity / 2);
    }
  }

  void pop_back() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    back_index = (back_index + capacity - 1) % capacity;
    --count;
    if (count > 0 && count == capacity / 4) {
      resize(capacity / 2);
    }
  }

  T &front() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    return buffer[front_index];
  }

  T &back() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    return buffer[(back_index + capacity - 1) % capacity];
  }

  const T &front() const {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    return buffer[front_index];
  }

  const T &back() const {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    return buffer[(back_index + capacity - 1) % capacity];
  }

  class Iterator {
  private:
    Deque<T> *deque_ptr;
    size_t pos;

  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    Iterator(Deque<T> *dq, size_t p) : deque_ptr(dq), pos(p) {}

    reference operator*() const {
      size_t index = (deque_ptr->front_index + pos) % deque_ptr->capacity;
      return deque_ptr->buffer[index];
    }

    // pointer operator->() const { return &(**this); }

    pointer operator->() const {
      size_t index = (deque_ptr->front_index + pos) % deque_ptr->capacity;
      return &(deque_ptr->buffer[index]);
    }

    Iterator &operator++() {
      ++pos;
      return *this;
    }

    Iterator operator++(int) {
      Iterator temp = *this;
      ++(*this); // 调用了前置++
      return temp;
    }

    // Iterator operator++(int) {
    //   Iterator temp = *this;
    //   ++pos;
    //   return temp;
    // }

    Iterator &operator--() {
      --pos;
      return *this;
    }

    Iterator operator--(int) {
      Iterator temp = *this;
      --(*this); // 调用了前置--
      return temp;
    }

    bool operator==(const Iterator &other) const {
      return deque_ptr == other.deque_ptr && pos == other.pos;
    }

    bool operator!=(const Iterator &other) const { return !(*this == other); }
  };

  Iterator begin() { return Iterator(this, 0); }
  Iterator end() { return Iterator(this, count); }
};
