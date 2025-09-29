#pragma once
#include <iostream>

template <typename T> struct Node {
  T _data;
  Node *next;
  Node *prev;
  Node(const T &data = T()) : _data(data), next(nullptr), prev(nullptr) {}
};

template <typename T> class List;

template <typename T> class Iterator {
public:
  using self_type = Iterator<T>;
  using value_type = T;
  using reference = T &;
  using pointer = T *;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;

  Iterator(Node<T> *ptr = nullptr) : _ptr(ptr) {}

  reference operator*() const { return _ptr->_data; }

  pointer operator->() const { return &(_ptr->_data); }

  self_type &operator++() {
    if (_ptr)
      _ptr = _ptr->next;
    return *this;
  }

  self_type operator++(int) {
    self_type tmp = *this;
    ++(*this);
    return tmp;
  }

  self_type &operator--() {
    if (_ptr)
      _ptr = _ptr->prev;
    return *this;
  }

  self_type operator--(int) {
    self_type tmp = *this;
    --(*this);
    return tmp;
  }

  bool operator==(const self_type &other) const { return _ptr == other._ptr; }

  bool operator!=(const self_type &other) const { return _ptr != other._ptr; }

private:
  Node<T> *_ptr;
  friend class List<T>;
};

template <typename T> class List {
public:
  using iterator = Iterator<T>;
  // using const_iterator = const Iterator<T>;
  List() {
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    tail->prev = head;
  }
  ~List() {
    clear();
    delete head;
    delete tail;
  }

  List(const List &other) = delete;
  List &operator=(const List &other) = delete;

  iterator insert(iterator pos, const T &value) {
    Node<T> *current = pos._ptr;
    Node<T> *newNode = new Node<T>(value);

    Node<T> *prevNode = current->prev;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = current;
    current->prev = newNode;

    return iterator(newNode);
  }

  iterator erase(iterator pos) {
    Node<T> *current = pos._ptr;
    if (current == head || current == tail) {
      return pos;
    }

    Node<T> *prevNode = current->prev;
    Node<T> *nextNode = current->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete current;
    return iterator(nextNode);
  }

  void push_front(const T &value) { insert(begin(), value); }

  void push_back(const T &value) { insert(end(), value); }

  void pop_front() {
    if (!empty())
      erase(begin());
  }

  void pop_back() {
    if (!empty()) {
      iterator it = end();
      --it;
      erase(it);
    }
  }

  T &front() { return head->next->_data; }

  T &back() { return tail->prev->_data; }

  bool empty() const { return head->next == tail; }

  size_t size() const {
    size_t count = 0;
    Node<T> *current = head->next;
    while (current != tail) {
      count++;
      current = current->next;
    }
    return count;
  }

  void print() {
    Node<T> *current = head->next;
    while (current != tail) {
      std::cout << current->_data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  void clear() {
    Node<T> *current = head->next;
    while (current != tail) {
      Node<T> *next = current->next;
      delete current;
      current = next;
    }
    head->next = tail;
    tail->prev = head;
  }

  iterator begin() { return iterator(head->next); }
  iterator end() { return iterator(tail); }

private:
  Node<T> *head;
  Node<T> *tail;
};
