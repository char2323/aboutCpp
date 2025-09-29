#include <iostream>
#include <utility>

void bubbleSort(int arr[], int n) {
  bool swapped;
  for (int i = 0; i < n - 1; ++i) {
    swapped = false;
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

void printarr(const int *arr, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  int n = 0;
  std::cout << "输入一个正数:";
  std::cin >> n;
  int *arr = new int[n];
  std::cout << "输入一组整数:";
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::cout << "排序前数组元素:" << std::endl;
  printarr(arr, n);
  bubbleSort(arr, n);
  std::cout << "排序后数组元素:" << std::endl;
  printarr(arr, n);
  delete[] arr;
  return 0;
}
