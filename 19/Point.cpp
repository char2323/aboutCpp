#include "Point.h"

Point operator-(const Point &a, const Point &b) {
  return Point(a.x_ - b.x_, a.y_ - b.y_);
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << "Point = (" << p.x_ << "," << p.y_ << ")\n";
  return os;
}
