#include <iostream>
#include <vector>

int sunRange(std::vector<int>::iterator start, std::vector<int>::iterator end) {
  // TODO
  int res = 0;
  for (auto it = start; it != end; ++it) {
    res += *it;
  }
  return res;
}

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6};
  int res = sunRange(vec.begin(), vec.end());
  std::cout << "result=" << res << std::endl;
  return 0;
}
