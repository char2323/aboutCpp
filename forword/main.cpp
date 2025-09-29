#include <climits>
#include <ios>
#include <iostream>
#include <type_traits>
#include <utility>

void func(int &x) { std::cout << "func(int&x)" << std::endl; }
void func(int &&x) { std::cout << "func(int&&x)" << std::endl; }

template <typename T> void check_reference(T &&x) {
  // std::cout << std::boolalpha;
  // std::cout << "T is a lvalue reference:" <<
  // std::is_lvalue_reference<T>::value
  //           << std::endl;
  // std::cout << "T is a rvalue reference:" <<
  // std::is_rvalue_reference<T>::value
  //           << std::endl;
  // std::cout << "x is lvalue:" <<
  // std::is_lvalue_reference<decltype((x))>::value
  //           << std::endl;
  // std::cout << "x is lvalue reference:"
  //           << std::is_lvalue_reference<decltype(x)>::value << std::endl;
  if (std::is_lvalue_reference<T>::value) {
    std::cout << "T is lvalue reference." << std::endl;
  } else {
    std::cout << "T is rvalue reference." << std::endl;
  }
  if (std::is_lvalue_reference<decltype(x)>::value) {
    std::cout << "x is lvalue reference." << std::endl;
  } else {
    std::cout << "x is rvalue reference." << std::endl;
  }
}

void process(int &x) { std::cout << "process(int& x)." << std::endl; }
void process(int &&x) { std::cout << "process(int&& x)." << std::endl; }

template <typename T> void wrapper(T &&x) { process(std::forward<T>(x)); }

template <typename T> void display_type(T &&param) {
  std::cout << "Type of T:"
            << (std::is_lvalue_reference<T>::value ? "lvalue reference"
                                                   : "rvalue reference")
            << ", "
            << (std::is_integral<typename std::remove_reference<T>::type>::value
                    ? "Integral"
                    : "Non-Integral")
            << std::endl;
}

int main() {

  int a = 10;
  int &b = a;
  int &&c = 20;
  int d = a + 5;
  std::string s1 = "fuck";
  std::string s2 = std::string("you");
  std::cout << "a: " << a << ",b: " << b << ",c: " << c << ",d: " << d
            << std::endl;

  std::cout << std::boolalpha;
  std::cout << "b is lvalue reference: "
            << std::is_lvalue_reference<decltype(b)>::value
            << std::endl; // is_lvalue_reference判断是否是左值引用
  std::cout << "a is lvalue: " << std::is_lvalue_reference<decltype((a))>::value
            << std::endl;
  func(a);
  func(10);

  std::cout << " ------------------- " << std::endl;
  // check_reference(a);
  // check_reference(20);
  // 右值引用类型作为表达式的时候，它其实是一个左值
  // check_reference(c);

  wrapper(a); // a是一个左值，所以经过原样转发，那么还是左值，所以打印的是int& x
  wrapper(10);           // 10是一个右值，打印的是int&& x
  wrapper(std::move(a)); // T被初始化为int,所以int&&还是右值

  std::cout << " ---------------------- " << std::endl;
  int x = 10;
  const int &y = x;
  display_type(x);
  display_type(20);
  display_type(y);
  display_type(std::move(x));

  return 0;
}
