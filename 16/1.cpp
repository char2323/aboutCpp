#include <iostream>
#include <ostream>
#include <sched.h>

class Complex {
public:
  double real, imag;
  Complex(double r = 0, double i = 0) : real(r), imag(i) {}

  Complex operator+(const Complex &c) {
    Complex temp;
    temp.real = this->real + c.real;
    temp.imag = this->imag + c.imag;
    return temp;
  }

  friend Complex operator-(const Complex &c1, const Complex &c2);
  friend std::ostream &operator<<(std::ostream &out, const Complex &c);
};

Complex operator-(const Complex &c1, const Complex &c2) {
  Complex temp;
  temp.real = c1.real - c2.real;
  temp.imag = c1.imag - c2.imag;
  return temp;
}
std::ostream &operator<<(std::ostream &out, const Complex &c) {
  out << c.real << "+" << c.imag << "i";
  return out;
}

int main(int argc, char *argv[]) {
  // Complex a, b, res;
  // a.real = 3;
  // a.imag = 4;
  // b.real = 5;
  // b.imag = 6;
  Complex a(5, 6);
  Complex b(1, 2);
  Complex res = a + b;
  std::cout << res.real << " " << res.imag << std::endl;
  std::cout << "a+b=" << res << std::endl;
  return 0;
}
