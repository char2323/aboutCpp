#pragma once

#include <ostream>
class Complex {
private:
  double real;
  double imag;

public:
  Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
  Complex operator+(const Complex &other) const {
    return Complex(this->real + other.real, this->imag + other.imag);
  }
  friend std::ostream &operator<<(std::ostream &os, const Complex &c) {
    os << "(" << c.real;
    if (c.imag >= 0)
      os << "+" << c.imag << "i)";
    else {
      os << "-" << -c.imag << "i)";
    }
    return os;
  }
  Complex operator-(const Complex &other) const {
    return Complex(this->real - other.real, this->imag - other.imag);
  }
  Complex operator*(const Complex &c) const {
    return Complex(real * c.real - imag * c.imag,
                   imag * c.real + real * c.imag);
  }
  Complex &operator=(const Complex &c) {
    if (this == &c)
      return *this;
    this->real = c.real;
    this->imag = c.imag;
    return *this;
  }

  bool operator==(const Complex &c) const {
    return real == c.real && imag == c.imag;
  }
};
