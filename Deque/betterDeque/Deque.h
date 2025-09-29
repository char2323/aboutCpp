#pragma once
#include <cassert> // 用于调试时断言，防止非法访问
#include <iostream>
#include <stdexcept>

/**
 * @brief 一个基于循环数组的双端队列（Deque）实现
 *
 * 特点：
 * - 支持 O(1) 时间复杂度的 push_front / push_back / pop_front / pop_back
 * 操作（摊还意义上）
 * - 自动扩容与收缩（类似 std::vector，但两端可操作）
 * - 提供简单的迭代器支持（可用于 range-based for）
 *
 * 与 std::deque 的区别：
 * - 本实现使用连续内存（环形数组），而 std::deque 使用分段内存
 * - 在极端情况下可能有更多的拷贝开销（resize 时需要搬运所有元素）
 */
template <typename T> class Deque {
private:
  T *buffer;           // 存储元素的循环数组指针
  size_t capacity;     // 当前缓冲区大小（总容量）
  size_t count;        // 当前存储的元素个数
  size_t front_index;  // 队首元素所在位置
  size_t back_index;   // 队尾下一个空位（即 push_back 的写入位置）
  size_t min_capacity; // 队列允许的最小容量，避免无限缩小导致频繁扩容

  /**
   * @brief 调整容量大小
   *
   * @param new_capacity 新的容量大小
   *
   * 注意事项：
   * - 如果 new_capacity < count，会强制提升到 count，以避免丢失数据
   * - 如果 new_capacity < min_capacity，会保持不变，避免无限缩小
   * - resize 会搬运所有元素，时间复杂度 O(n)
   */
  void resize(size_t new_capacity) {
    if (new_capacity < count) {
      new_capacity = count; // 容量至少要能容纳现有元素
    }
    if (new_capacity < min_capacity) {
      return; // 不允许缩小到 min_capacity 以下
    }

    // 分配新的缓冲区
    T *new_buffer = new T[new_capacity];
    // 搬运旧元素到新缓冲区（保持逻辑顺序）
    for (size_t i = 0; i < count; ++i) {
      new_buffer[i] = buffer[(front_index + i) % capacity];
    }

    // 释放旧缓冲区
    delete[] buffer;

    // 更新状态
    buffer = new_buffer;
    capacity = new_capacity;
    front_index = 0;               // 队首重置为 0
    back_index = count % capacity; // 队尾位置 = 元素个数
  }

public:
  /**
   * @brief 构造函数
   *
   * @param initial_capacity 初始容量（默认 10）
   */
  Deque(size_t initial_capacity = 10)
      : capacity(initial_capacity), count(0), front_index(0), back_index(0),
        min_capacity(initial_capacity) {
    buffer = new T[capacity];
  }

  /// 析构函数：释放动态数组
  ~Deque() { delete[] buffer; }

  // ========== Rule of 5 ==========

  /// 拷贝构造函数
  Deque(const Deque &other)
      : capacity(other.capacity), count(other.count),
        front_index(other.front_index), back_index(other.back_index),
        min_capacity(other.min_capacity) {
    buffer = new T[capacity];
    for (size_t i = 0; i < capacity; ++i) {
      buffer[i] = other.buffer[i];
    }
  }

  /// 拷贝赋值运算符（采用 copy-and-swap 技巧，异常安全）
  Deque &operator=(Deque other) {
    std::swap(buffer, other.buffer);
    std::swap(capacity, other.capacity);
    std::swap(count, other.count);
    std::swap(front_index, other.front_index);
    std::swap(back_index, other.back_index);
    std::swap(min_capacity, other.min_capacity);
    return *this;
  }

  /// 移动构造函数
  Deque(Deque &&other) noexcept
      : buffer(other.buffer), capacity(other.capacity), count(other.count),
        front_index(other.front_index), back_index(other.back_index),
        min_capacity(other.min_capacity) {
    other.buffer = nullptr;
    other.count = other.capacity = 0;
  }

  /// 移动赋值运算符
  Deque &operator=(Deque &&other) noexcept {
    if (this != &other) {
      delete[] buffer; // 释放当前资源
      buffer = other.buffer;
      capacity = other.capacity;
      count = other.count;
      front_index = other.front_index;
      back_index = other.back_index;
      min_capacity = other.min_capacity;

      // 清空来源对象，避免悬挂指针
      other.buffer = nullptr;
      other.count = other.capacity = 0;
    }
    return *this;
  }

  // ========== 基本操作 ==========

  /// 队列是否为空
  bool empty() const { return count == 0; }

  /// 队列大小（当前元素个数）
  size_t size() const { return count; }

  /// 从队首插入元素
  void push_front(const T &value) {
    if (count == capacity)
      resize(capacity * 2);                                // 满了就扩容
    front_index = (front_index + capacity - 1) % capacity; // 环形向前移动
    buffer[front_index] = value;
    ++count;
  }

  /// 从队尾插入元素
  void push_back(const T &value) {
    if (count == capacity)
      resize(capacity * 2);
    buffer[back_index] = value;
    back_index = (back_index + 1) % capacity; // 环形向后移动
    ++count;
  }

  /// 从队首删除元素
  void pop_front() {
    if (empty())
      throw std::out_of_range("Deque is empty");
    front_index = (front_index + 1) % capacity;
    --count;
    if (count > 0 && count == capacity / 4) {
      resize(capacity / 2); // 过于稀疏则收缩
    }
  }

  /// 从队尾删除元素
  void pop_back() {
    if (empty())
      throw std::out_of_range("Deque is empty");
    back_index = (back_index + capacity - 1) % capacity;
    --count;
    if (count > 0 && count == capacity / 4) {
      resize(capacity / 2);
    }
  }

  /// 访问队首元素（非 const 版本）
  T &front() {
    if (empty())
      throw std::out_of_range("Deque is empty");
    return buffer[front_index];
  }

  /// 访问队尾元素（非 const 版本）
  T &back() {
    if (empty())
      throw std::out_of_range("Deque is empty");
    return buffer[(back_index + capacity - 1) % capacity];
  }

  /// 访问队首元素（const 版本）
  const T &front() const {
    if (empty())
      throw std::out_of_range("Deque is empty");
    return buffer[front_index];
  }

  /// 访问队尾元素（const 版本）
  const T &back() const {
    if (empty())
      throw std::out_of_range("Deque is empty");
    return buffer[(back_index + capacity - 1) % capacity];
  }

  // ========== 迭代器实现 ==========
  class Iterator {
  private:
    Deque<T> *deque_ptr; // 指向关联的 Deque
    size_t pos;          // 相对于队首的偏移量 [0, count]

  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    Iterator(Deque<T> *dq, size_t p) : deque_ptr(dq), pos(p) {}

    /// 解引用操作
    reference operator*() const {
      assert(pos < deque_ptr->count && "Iterator out of range");
      size_t index = (deque_ptr->front_index + pos) % deque_ptr->capacity;
      return deque_ptr->buffer[index];
    }

    /// 成员访问操作
    pointer operator->() const { return &(**this); }

    /// 前置自增
    Iterator &operator++() {
      ++pos;
      return *this;
    }

    /// 后置自增
    Iterator operator++(int) {
      Iterator temp = *this;
      ++(*this);
      return temp;
    }

    /// 前置自减
    Iterator &operator--() {
      --pos;
      return *this;
    }

    /// 后置自减
    Iterator operator--(int) {
      Iterator temp = *this;
      --(*this);
      return temp;
    }

    /// 比较运算
    bool operator==(const Iterator &other) const {
      return deque_ptr == other.deque_ptr && pos == other.pos;
    }
    bool operator!=(const Iterator &other) const { return !(*this == other); }
  };

  /// 返回指向队首的迭代器
  Iterator begin() { return Iterator(this, 0); }

  /// 返回指向队尾的迭代器（指向末尾后一个位置）
  Iterator end() { return Iterator(this, count); }
};
