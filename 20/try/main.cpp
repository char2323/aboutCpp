#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Base {
public:
  void display() const { std::cout << "display from base" << std::endl; }
  virtual void show() const { std::cout << "show from base" << std::endl; }
  virtual ~Base() {}
};

class Derived : public Base {
public:
  void display() const { std::cout << "display from Derived" << std::endl; }
  void callBaseDisplay() const { Base::display(); }
  void show() const { std::cout << "show from Derived" << std::endl; }
};

class Shape {
public:
  virtual void draw() const { std::cout << "Drawing a generic shape.\n"; }
  virtual ~Shape() {};
};

class Circle : public Shape {
  void draw() const override { std::cout << "Drawing a Circle.\n"; }
};

class Rectangle : public Shape {
  void draw() const override { std::cout << "Drawing a Rectangle.\n"; }
};

class Calculator {
public:
  int add(int a, int b) { return a + b; }
  double add(double a, double b) { return a + b; }
};

class AdvanceCalculator : public Calculator {
public:
  using Calculator::add;
  int add(int a, int b, int c) { return a + b + c; }
};

class Animal {
public:
  virtual void makeSound() const = 0;
  virtual ~Animal() {}
};

class Dog : public Animal {
public:
  void makeSound() const override { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
  void makeSound() const override { std::cout << "Meow!\n"; }
};

class Vehicle {
public:
  Vehicle() { std::cout << "Vehicle constructor.\n"; }
  virtual ~Vehicle() { std::cout << "Vehicle destructor.\n"; }
};

class Car : public Vehicle {
public:
  Car() { std::cout << "Car constructor.\n"; }
  ~Car() { std::cout << "Car destructor.\n"; }
};

int main(int argc, char *argv[]) {
  // Derived d;
  // d.display();
  // d.callBaseDisplay();
  // d.show();
  //
  // Base *bPtr = &d;
  // bPtr->display();
  // bPtr->show();

  // std::vector<std::unique_ptr<Base>> vec;
  // vec.emplace_back(std::make_unique<Derived>());
  // vec[0]->show();

  // std::vector<std::unique_ptr<Shape>> vec;
  // vec.emplace_back(std::make_unique<Shape>());
  // vec.emplace_back(std::make_unique<Circle>());
  // vec.emplace_back(std::make_unique<Rectangle>());
  //
  // for (const auto &shape_ptr : vec) {
  //   shape_ptr->draw();
  // }

  // AdvanceCalculator a;
  // std::cout << a.add(1, 2, 3) << std::endl;
  // std::cout << a.add(1, 2) << std::endl;
  // std::cout << a.add(11.1, 2.3) << std::endl;

  // std::unique_ptr<Animal> pDog = std::make_unique<Dog>();
  // std::unique_ptr<Animal> pCat = std::make_unique<Cat>();
  //
  // pDog->makeSound();
  // pCat->makeSound();
  //
  // Dog mydog;
  // Cat mycat;
  // mydog.makeSound();
  // mycat.makeSound();

  Car c;

  return 0;
}
