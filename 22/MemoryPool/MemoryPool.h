#pragma once
#include <cstddef>
#include <cstdlib>
#include <new>
#include <stack>

class MemoryPool {
private:
  // 单个元素的大小
  size_t objsize_;
  // 元素个数
  size_t objcount_;
  // 字节流的指针（内存池）
  char *pool;
  std::stack<void *> freeList;

public:
  MemoryPool(size_t objsize, size_t objcount)
      : objsize_(objsize), objcount_(objcount),
        pool((char *)malloc(objsize * objcount)) {
    if (pool == nullptr) {
      throw std::bad_alloc();
    }
    for (size_t i = 0; i < objcount; ++i) {
      freeList.push(pool + i * objsize);
    }
  }
  ~MemoryPool() { free(pool); }
  void *allocate();
  void deallocate(void *ptr);
};
