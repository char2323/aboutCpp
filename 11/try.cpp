#include <cctype>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <regex>
#include <stdexcept>
#include <string>

int main(int argc, char *argv[]) {
  std::string text = "i like cats";
  std::string from = "cats";
  std::string to = "dogs";

  size_t pos = text.find(from);
  if (pos != std::string::npos) {
    text.replace(pos, from.length(), to);
    std::cout << "替换后:" << text << std::endl;
  } else {
    std::cout << "'" << from << "'未找到." << std::endl;
  }
  std::cout << text.capacity() << std::endl;

  std::string str = "ABCDE";
  std::cout << str[0] << std::endl;
  if (std::isupper(str[0])) {
    std::cout << "大写" << std::endl;
  } else {
    std::cout << "小写" << std::endl;
  }

  for (int i = 0; i < str.length(); i++) {
    std::cout << str[i] << std::endl;
  }

  for (int i = str.length() - 1; i >= 0; i--) {
    std::cout << str[i] << std::endl;
  }

  try {
    std::cout << str.at(100) << std::endl;
  } catch (std::out_of_range e) {
    std::cout << "越界访问" << std::endl;
  }

  str = "FUCK YOU BITCH";
  for (auto iter = str.begin(); iter != str.end(); ++iter) {
    *iter = std::tolower(*iter);
  }
  std::cout << str << std::endl;
  std::cout << str.c_str() << std::endl;

  std::string text1 = "The quick brown fox jumps over the lazy dog.";
  std::regex pattern(R"(\b\w{5}\b)"); // 匹配所有5个字母的单词

  std::sregex_iterator it(text1.begin(), text1.end(), pattern);
  std::sregex_iterator end;

  std::cout << "5个字母的单词有:" << std::endl;
  while (it != end) {
    std::cout << (*it).str() << std::endl;
    ++it;
  }
  return 0;
}
