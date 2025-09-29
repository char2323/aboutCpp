#include <iostream>
#include <regex>
#include <string>

bool isCalidEmail(const std::string &email) {
  const std::regex pattern(R"((\w+)(\.?\w+)*@(\w+)(\.\w+)+)");
  return std::regex_match(email, pattern);
}

int main(int argc, char *argv[]) {
  std::string email;
  std::cout << "请输入你的邮箱:";
  std::cin >> email;

  if (isCalidEmail(email)) {
    std::cout << "有效的地址" << std::endl;
  } else {
    std::cout << "无效的地址" << std::endl;
  }
  return 0;
}
