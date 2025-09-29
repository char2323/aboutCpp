// 创建一个程序，接受用户输入的一段文本，并提供以下功能：
//
// 统计单词数量
// 统计每个单词出现的次数
// 查找指定单词的出现次数
// 输出最长的单词

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <limits> // For std::numeric_limits

int main() {
    std::cout << "请输入一段文本（结束请输入Ctrl+D/Ctrl+Z）：\n";
    std::string text;

    // 读取所有行，直到输入结束
    std::string line;
    while (std::getline(std::cin, line)) {
        text += line + " ";
    }

    // 统计单词
    std::stringstream ss(text);
    std::string word;
    std::map<std::string, int> wordCount;
    size_t totalWords = 0;
    std::string longestWord;

    while (ss >> word) {
        // 清理并转为小写
        word.erase(std::remove_if(word.begin(), word.end(),
                                  [](char c) { return std::ispunct(c); }),
                   word.end());
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (!word.empty()) {
            wordCount[word]++;
            totalWords++;
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
        }
    }

    // 输出统计结果
    std::cout << "\n统计结果:\n";
    std::cout << "总单词数: " << totalWords << std::endl;
    std::cout << "每个单词出现的次数:\n";
    for (const auto &pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << "最长的单词: " << longestWord << std::endl;

    // 清空 std::cin 的状态，以便进行第二次输入
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 查找指定单词
    std::string searchWord;
    std::cout << "\n请输入要查找的单词: ";
    std::getline(std::cin, searchWord); // 使用 getline 来读取整个查找行
    
    // 清理和转换查找词
    searchWord.erase(std::remove_if(searchWord.begin(), searchWord.end(),
                                  [](char c) { return std::ispunct(c); }),
                   searchWord.end());
    std::transform(searchWord.begin(), searchWord.end(), searchWord.begin(), ::tolower);

    auto it = wordCount.find(searchWord);
    if (it != wordCount.end()) {
        std::cout << "'" << searchWord << "' 出现了 " << it->second << " 次。" << std::endl;
    } else {
        std::cout << "'" << searchWord << "' 未在文本中找到。" << std::endl;
    }

    return 0;
}