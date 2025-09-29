#include <iostream>
#include <new>
#include <stdexcept>

double divide(double num, double denom) {
  if (denom == 0) {
    throw std::invalid_argument("Denominator cannot be zero.");
  }
  return num / denom;
}

int getElement(int array[], int size, int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index is out of ranger");
  }
  return array[index];
}

int main(int argc, char *argv[]) {
  // {
  // double num, denom;
  // std::cout << "Enter numerator:";
  // std::cin >> num;
  // std::cout << "Enter denominator:";
  // std::cin >> denom;
  //
  // try {
  //   double result = divide(num, denom);
  //   std::cout << "Result:" << result << std::endl;
  // } catch (std::invalid_argument &e) {
  //   std::cerr << "Error:" << e.what() << std::endl;
  // }
  // std::cout << "Program continues after try-catch." << std::endl;
  // }

  // try {
  //   int choice;
  //   std::cout << "Choose exception to throw(1: bad_alloc,2:
  //   invalid_argument):"; std::cin >> choice; if (choice == 1) {
  //     throw std::bad_alloc();
  //   } else if (choice == 2) {
  //     throw std::invalid_argument("Invalid argument provided.");
  //   } else {
  //     std::cout << "No exception thrown." << std::endl;
  //   }
  // } catch (std::bad_alloc &e) {
  //   std::cerr << "Caught std::bad_alloc: " << e.what() << std::endl;
  // } catch (std::invalid_argument &e) {
  //   std::cerr << "Caught std::invalid_argument: " << e.what() << std::endl;
  // }
  // std::cout << "Program continues after try-catch." << std::endl;

  int myarray[5] = {10, 20, 30, 40, 50};
  int index;
  std::cout << "Enter array index(0-4):";
  std::cin >> index;

  try {
    int value = getElement(myarray, 5, index);
    std::cout << "Element at index " << index << " is : " << value << std::endl;
  } catch (std::out_of_range &e) {
    std::cerr << "Erroe: " << e.what() << std::endl;
  }

  return 0;
}
