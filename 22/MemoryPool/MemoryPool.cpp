#include "MemoryPool.h"
#include <new>

void *MemoryPool::allocate() {
  if (freeList.empty()) {
    throw std::bad_alloc();
  }
  void *ptr = freeList.top();
  freeList.pop();
  return ptr;
}
void MemoryPool::deallocate(void *ptr) { freeList.push((char *)ptr); }
