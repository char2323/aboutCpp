#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {

  {
    // 把字符串中的第一个单词改为大写
    std::string s = "Charmmy is a handsome boy.";
    for (auto it = s.begin(); it != s.end() && !std::isspace(*it); ++it) {
      *it = toupper(*it);
    }
    std::cout << s << std::endl;
  }
  {
    // vector容器存储了一系列数字，在循环中遍历每一个元素，并且删除其中的奇数，要求循环结束，vector元素为偶数，要求时间复杂度o(n)
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    for (auto it = vec.begin(); it != vec.end();) {
      if (*it % 2 != 0) {
        it = vec.erase(it);
        continue;
      }
      ++it;
    }
    for (auto num : vec) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }

  {
    // 使用迭代器完成二分搜索
    std::vector<int> num = {1, 2, 3, 4, 5};
    auto beg = num.begin(), end = num.end();
    auto mid = beg + num.size() / 2;
    int find = 10;
    while (mid != end && *mid != find) {
      if (find < *mid) {
        end = mid;
      } else {
        beg = mid + 1;
      }
      mid = beg + (end - beg) / 2;
    }
    if (mid != end) {
      std::cout << find << " is found." << std::endl;
    } else {
      std::cout << find << " is not found." << std::endl;
    }
  }

  // {
  //   // 编写一个程序，读取一组整数到一个 std::vector
  //   // 中，并打印每对相邻元素的和。例如，给定输入 1 2 3 4，输出应为 3 5 7。
  //   std::vector<int> number;
  //   int num;
  //   std::cout << "请输入一组整数，使用空格分割，以-1结束" << std::endl;
  //   while (std::cin >> num && num != -1) {
  //     number.push_back(num);
  //   }
  //
  //   std::cout << "相邻元素的和:" << std::endl;
  //   auto beg = number.begin(), end = number.end();
  //   auto next = beg + 1;
  //   int res = 0;
  //   while (next != end) {
  //     std::cout << *beg + *next << " ";
  //     beg++;
  //     next++;
  //   }
  //   std::cout<<std::endl;
  // }

  // {
  //   // 编写一个程序，从用户输入一组整数到一个 std::vector
  //   // 中，然后使用迭代器反向打印这些元素。
  //   std::vector<int> number;
  //   int num;
  //   std::cout << "请输入一组整数，使用空格分割，以-1结束" << std::endl;
  //   while (std::cin >> num && num != -1) {
  //     number.push_back(num);
  //   }
  //   std::cout << "反向打印结果:";
  //   for (std::vector<int>::reverse_iterator it = number.rbegin();
  //        it != number.rend(); ++it) {
  //     std::cout << *it << " ";
  //   }
  //   std::cout << std::endl;
  // }

  {
    // 描述： 编写一个程序，创建两个
    // std::vector，从用户输入填充它们。使用迭代器将这两个 vector 合并为一个新
    // vector。

    int num;
    std::vector<int> number1;
    std::cout << "请输入第一组整数，使用空格分割，以-1结束" << std::endl;
    while (std::cin >> num && num != -1) {
      number1.push_back(num);
    }
    std::vector<int> number2;
    std::cout << "请输入第二组，使用空格分割，以-1结束" << std::endl;
    while (std::cin >> num && num != -1) {
      number2.push_back(num);
    }
    std::vector<int> res;

    std::cout << "基础方法:" << std::endl;
    for (auto it = number1.begin(); it != number1.end(); ++it) {
      res.push_back(*it);
    }
    for (auto it = number2.begin(); it != number2.end(); ++it) {
      res.push_back(*it);
    }

    std::cout << "合并后:";
    for (auto it = res.begin(); it != res.end(); ++it) {
      std::cout << *it << " ";
    }

    std::cout << std::endl;

    std::cout << "法二:" << std::endl;
    // 合并两个向量
    res.clear();
    res.insert(res.end(), number1.begin(), number1.end());
    res.insert(res.end(), number2.begin(), number2.end());

    std::cout << "合并后:";
    for (auto it = res.begin(); it != res.end(); ++it) {
      std::cout << *it << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}
