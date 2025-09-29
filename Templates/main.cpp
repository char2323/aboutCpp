#include "template.h"
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::cout << maxValue(1, 2) << std::endl;
  std::cout << maxValue(1.1, 2.2) << std::endl;

  Pair p(1, 2); // 注意这里用了自动类型推导，但是注意这个要求cpp17+
  Pair<double, double> p2(1.1, 2.2); // 一般来说都要<T>
  p.print();
  p2.print();

  std::vector<std::string> name = {"charming", "charmmy", "Alice"};
  for (auto s : name) {
    std::cout << s << " ";
  }
  std::cout << std::endl;

  FixedArray<int, 10> array;
  for (int i = 0; i < 10; ++i) {
    array[i] = i;
  }
  array.print();

  ContainerPrinter<std::vector, std::string> c;
  std::vector<std::string> vec = name;
  c.Printer(vec);

  Printer<int> int_printer;
  int_printer.printer(10);

  Printer<std::string> str_printer;
  str_printer.printer("hello");

  double value = 1.1;
  Pair<std::string, double *> pair("abc", &value);
  pair.print();

  int abc = 10;
  printValue(&abc);

  std::string str = "charmmy";
  printValue(str);

  printAll(10, 20, 50, "charming");
  coutAll(10, 20, 50, "charming");
  std::cout << std::endl;

  std::cout << sumAll(10, 20, 20.1, 3.232) << std::endl;

  std::cout << allNot(false, false, true) << std::endl;

  std::cout << sumAll(1, 2, 3, 4, 5) << std::endl;

  std::cout << multiRightFold(1, 2, 3, 4, 5) << std::endl;

  print_all(1, 2, 3, 4, 5);

  MyPoint mp1(1, 2);
  MyPoint mp2(3, 4);
  MyPoint mp3(5, 6);
  auto res = sumPoints(mp1, mp2, mp3);
  std::cout << res._x << " " << res._y << std::endl;
  return 0;
}
