#include <iostream>
#include <list>

int main(int argc, char *argv[]) {
  std::list<int> numbers;
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  for (int number : numbers) {
    std::cout << number << " ";
  }
  std::cout << std::endl;
  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  auto it = numbers.begin();
  ++it;
  numbers.insert(it, 10);
  for (int number : numbers) {
    std::cout << number << " ";
  }
  std::cout << std::endl;
  numbers.push_back(2);
  for (int number : numbers) {
    std::cout << number << " ";
  }
  std::cout << std::endl;
  numbers.remove(2); // remove all elements with value 2
  for (int number : numbers) {
    std::cout << number << " ";
  }
  std::cout << std::endl;
  auto end_it = numbers.end();
  --end_it;              // point to the last element
  --end_it;              // point to the second last element
  numbers.erase(end_it); // remove the second last element
  for (int number : numbers) {
    std::cout << number << " ";
  }
  std::cout << std::endl;
  return 0;
}
