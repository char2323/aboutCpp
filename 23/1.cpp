#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

// 定义函数指针类型的变量
int (*funcPtr)(int, int);

// 定义一个普通的函数
int add(int a, int b) { return a + b; }

struct Multiply {
  int operator()(int a, int b) { return a * b; }
};

struct Adder {
  // int operator()(int a, int b) { return a + b; }
  int to_add;
  Adder(int value) : to_add(value) {}
  int operator()(int a) { return a + to_add; }
  void add(int x) { to_add += x; }
};

struct IsGreater {
  int threshold;
  IsGreater(int value) : threshold(value) {}
  bool operator()(int x) { return x > threshold; }
};

template <typename T> struct Compare {
  bool operator()(const T &a, const T &b) const { return a < b; };
};

class Processor {
private:
  int _threshold;

public:
  Processor(int threshold) : _threshold(threshold) {}
  void process(std::vector<int> &data) {
    std::cout << "before process: " << std::endl;
    for (const auto &num : data) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
    data.erase(std::remove_if(data.begin(), data.end(),
                              [this](int n) { return n < _threshold; }),
               data.end());
    std::cout << "after process: " << std::endl;
    for (const auto &num : data) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
};

using Callback = std::function<void(int)>;

// 触发事件
void triggerEvent(Callback cb, int value) {
  // 模拟一些操作
  std::cout << "Triggering event with value: " << value << std::endl;
  // 调用回调函数
  cb(value);
}

void print(int a, int b, int c) {
  std::cout << "print: " << a << ", " << b << ", " << c << std::endl;
}

// void print_pint(int *ptr) { *ptr = 100; }

int main(int argc, char *argv[]) {
  // int *p_int = new int(5);
  // std::cout << *p_int << std::endl;
  // print_pint(p_int);
  // std::cout << *p_int << std::endl;
  // delete p_int;
  //
  // return 0;

  // 函数指针变量指向普通函数
  funcPtr = add;
  // 等价于funcPtr = &add;
  int result = funcPtr(1, 2); // 等价于(*funcPtr)(1,2);
  std::cout << "Result: " << result << std::endl;
  Adder adder(5);
  std::cout << "Result: " << adder(20) << std::endl;

  std::vector<int> numbers = {10, 20, 30, 40, 50};
  IsGreater isGreaterThan25(25);
  auto it = std::find_if(numbers.begin(), numbers.end(), isGreaterThan25);
  if (it != numbers.end()) {
    std::cout << "First number greater than 25 is: " << *it << std::endl;
  } else {
    std::cout << "No number greater than 25 found." << std::endl;
  }

  std::vector<int> nums = {30, 20, 10, 50, 40};

  std::sort(nums.begin(), nums.end(), Compare<int>());
  std::cout << "Sorted numbers: ";
  for (const auto &num : nums) {
    std::cout << num << " ";
  }
  for (const auto &num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  {
    int threshold = 25;
    std::vector<int> numbers = {10, 30, 20, 60, 50};
    // 使用lambda表达式
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(),
                                 [threshold](int x) { return x < threshold; }),
                  numbers.end());
    // remove_if返回的是一个新的逻辑结尾迭代器;它将符合条件的移动到后面，不符合条件的移动到前面;
    // 需要使用erase将逻辑结尾之后的元素删除;erase的第一个参数是要删除的第一个元素的迭代器，第二个参数是要删除的最后一个元素的下一个位置的迭代器
    // numbers.erase(new_end, numbers.end());
    std::cout << "Numbers greater than " << threshold << ": ";
    for (const auto &num : numbers) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
  {
    int temp = 2;
    int *ptemp = &temp;
    auto lambda1 = [&temp](int a) { temp *= a; };
    lambda1(3);
    std::cout << "temp: " << temp << std::endl;
    auto lambda2 = [ptemp](int a) { *ptemp += a; };
    lambda2(5);
    std::cout << "temp: " << temp << std::endl;
  }
  {
    auto add_ptr = std::make_shared<Adder>(10);
    auto lambda3 = [add_ptr](int a) { add_ptr->add(a); };
    lambda3(5);
    std::cout << "add_ptr->to_add: " << add_ptr->to_add << std::endl;
    std::cout << add_ptr.use_count() << std::endl;
  }
  {
    int fibonacci[10] = {0, 1};
    auto fib = [&fibonacci, n = 0]() mutable {
      // n=2开始
      // if (n < 10) {
      //   fibonacci[n] = fibonacci[n - 1] + fibonacci[n - 2];
      //   ++n;
      //   return fibonacci[n - 1];
      if (n < 10) {
        if (n < 2) {
          return fibonacci[n++];
        }
        fibonacci[n] = fibonacci[n - 1] + fibonacci[n - 2];
        return fibonacci[n++];
      } else {
        return -1; // Indicate that the sequence is complete
      }
    };
    std::cout << "Fibonacci sequence: ";
    for (int i = 0; i < 10; ++i) {
      std::cout << fib() << " ";
    }
    std::cout << std::endl;
  }
  {
    int fibonacci[10] = {0, 1};
    // auto fib = [&fibonacci, n = 2]() mutable {
    //   for (; n < 10; ++n) {
    //     fibonacci[n] = fibonacci[n - 1] + fibonacci[n - 2];
    //   }
    // };
    // fib();
    for (int i = 2; i < 10; ++i) {
      fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    std::cout << "Fibonacci sequence: ";
    for (int i = 0; i < 10; ++i) {
      std::cout << fibonacci[i] << " ";
    }
    std::cout << std::endl;
  }
  {
    Processor precessor(25);
    std::vector<int> data = {10, 30, 20, 60, 50};
    precessor.process(data);
  }
  {
    // function对象——function可以接受任何可调用对象，包括普通函数、仿函数、lambda表达式等
    // 封装普通函数
    std::function<int(int, int)> func = add;
    std::cout << "func(3, 4): " << func(3, 4) << std::endl;

    // 接受仿函数
    Multiply multiply;
    std::function<int(int, int)> func2 = multiply;
    std::cout << "func2(3, 4): " << func2(3, 4) << std::endl;

    // 接受lambda表达式
    std::function<int(int, int)> func3 = [](int a, int b) { return a - b; };
    std::cout << "func3(7, 4): " << func3(7, 4) << std::endl;

    // 使用std::function作为回调函数类型
    Callback callback = [](int value) {
      std::cout << "Callback called with value: " << value << std::endl;
    };
    triggerEvent(callback, 42);

    std::vector<std::function<int(int, int)>> operations;
    operations.emplace_back(add); // 注意emplace_back可以减少一次拷贝构造的开销
    operations.emplace_back(Multiply());
    operations.emplace_back([](int a, int b) { return a - b; });

    for (const auto &op : operations) {
      std::cout << "Operation result: " << op(10, 5) << std::endl;
    }
  }
  {
    // bind
    auto new_add = std::bind(add, 10, std::placeholders::_1);
    std::cout << "new_add(5): " << new_add(5) << std::endl;
    auto new_func = std::bind(print, std::placeholders::_3,
                              std::placeholders::_2, std::placeholders::_1);
    new_func(1, 2, 3);

    auto new_func2 = [](int b) { return add(10, b); };
    std::cout << "new_func2(5): " << new_func2(5) << std::endl;

    auto new_func3 =
        std::bind(&Adder::operator(), Adder(20), std::placeholders::_1);
    std::cout << "new_func3(5): " << new_func3(5) << std::endl;

    Adder adder(30);
    auto new_func4 = std::bind(&Adder::add, &adder, std::placeholders::_1);
    // &adder传递的是对象的地址，这样在new_func4中修改adder的成员变量to_add会影响到外部的adder对象
    // 如果传递的是对象本身，即std::bind(&Adder::add, adder,
    // std::placeholders::_1);
    // 那么在new_func4中修改adder的成员变量to_add不会影响到外部的adder对象，因为传递的是对象的副本
    // 这个传递是必要的，需要让bind找到成员函数对应的对象；如果是静态成员函数或者普通函数，则不需要传递对象
    std::cout << "adder.to_add before: " << adder.to_add << std::endl;
    new_func4(10);
    std::cout << "adder.to_add after: " << adder.to_add << std::endl;
  }
  return 0;
}
