#include <iostream>
#include <vector>

// 递归：
int fibonacciRecursive(int n) {
  if (n < 0) {
    std::cout << "不能为负数！" << std::endl;
    return -1;
  }
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

std::vector<unsigned long long> generateFibonacciRecursive(int n) {
  std::vector<unsigned long long> fibonacci;
  for (int i = 0; i < n; ++i) {
    fibonacci.push_back(fibonacciRecursive(i));
  }
  return fibonacci;
}

// 循环：
std::vector<unsigned long long> generateFibonacci(int n) {
  std::vector<unsigned long long> fib;
  if (n <= 0) {
    return fib;
  }
  fib.push_back(0);
  if (n == 1) {
    return fib;
  }
  fib.push_back(1);
  for (int i = 2; i < n; ++i) {
    unsigned long long next = fib[i - 1] + fib[i - 2];
    fib.push_back(next);
  }
  return fib;
}

// 动态规划：
std::vector<unsigned long long> fibonacciDynamic(int n) {
  std::vector<unsigned long long> fib(n);
  fib[0] = 0;
  if (n > 1) {
    fib[1] = 1;
  }
  for (int i = 2; i < n; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib;
}

void printfibonacci(const std::vector<unsigned long long> &fib) {
  for (int i = 0; i < fib.size(); ++i) {
    std::cout << fib[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  // 斐波那契数列
  std::cout << "请输入斐波那契数列的项数: ";
  int n = 0;
  std::cin >> n;
  // 递归方式：
  printfibonacci(generateFibonacciRecursive(n));
  printfibonacci(generateFibonacci(n));
  printfibonacci(fibonacciDynamic(n));
  return 0;
}
