#include "sfinae.h"
#include <iostream>

int main() {
  print_type(3.14);
  const char *a = "hello";
  print_type(a);
  print_type("fuck");
  int x = 100;
  print_type(&x);

  std::cout << " ---------------------- " << std::endl;
  cout_type(3.14);
  cout_type(a);
  cout_type(&x);
  return 0;
}
