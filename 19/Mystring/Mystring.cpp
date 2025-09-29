#include "Mystring.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Mystring &str) {
  if (str.data_) {
    os << str.data_;
  }
  return os;
}
