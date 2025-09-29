#pragma once
#include <iostream>
#include <ostream>
#include <random>
#include <string>

class Point {
private:
  double x_;
  double y_;

public:
  Point(double x, double y) : x_(x), y_(y) {}
  Point(const Point &other) : x_(other.x_), y_(other.y_) {}
  Point operator+(const Point &other) {
    return Point(this->x_ + other.x_, y_ + other.y_);
  }
  friend Point operator-(const Point &a, const Point &b);
  inline void print() const { std::cout << "(" << x_ << "," << y_ << ")\n"; }
  friend std::ostream &operator<<(std::ostream &os, const Point &p);
};
