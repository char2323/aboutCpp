#include "List.h"
#include <chrono>
#include <iostream>
using namespace std;

// 一个简单的 O(n) size 版本（模拟旧写法）
template <typename T> size_t slow_size(const List<T> &lst) {
  size_t count = 0;
  for (auto it = lst.begin(); it != lst.end(); ++it) {
    count++;
  }
  return count;
}

int main() {
  List<int> lst;

  // ====== 功能测试 ======
  cout << "功能测试:" << endl;

  lst.push_back(10);
  lst.push_back(20);
  lst.push_front(5);
  lst.push_back(30);

  cout << "链表内容: ";
  lst.print();

  cout << "front = " << lst.front() << ", back = " << lst.back() << endl;
  cout << "size = " << lst.size() << endl;

  lst.pop_front();
  lst.pop_back();

  cout << "删除首尾后: ";
  lst.print();
  cout << "size = " << lst.size() << endl;

  // ====== 性能对比 ======
  cout << "\n性能测试 (插入1000000个元素):" << endl;

  const int N = 1'000'000;
  List<int> bigList;
  for (int i = 0; i < N; i++) {
    bigList.push_back(i);
  }

  // 用 fast size() 测试
  auto start = chrono::high_resolution_clock::now();
  size_t s1 = bigList.size(); // O(1)
  auto end = chrono::high_resolution_clock::now();
  auto fast_time =
      chrono::duration_cast<chrono::microseconds>(end - start).count();

  // 用 slow_size() 测试
  start = chrono::high_resolution_clock::now();
  size_t s2 = slow_size(bigList); // O(n)
  end = chrono::high_resolution_clock::now();
  auto slow_time =
      chrono::duration_cast<chrono::milliseconds>(end - start).count();

  cout << "fast size() = " << s1 << " , 耗时 " << fast_time << " 微秒" << endl;
  cout << "slow size() = " << s2 << " , 耗时 " << slow_time << " 毫秒" << endl;

  return 0;
}
