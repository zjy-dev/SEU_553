#include <cstring>
#include <iostream>
using namespace std;

int main() {
  char s[50] = "(025)87234865-987";

  // char *strtok(char *str, const char *d)
  // 它会把从 str 开始遇到的第一个 d 改成 '\0'
  // 返回值是从 str 开始第一个指向的值不是 d 的指针, 一般就是 str
  // 如果传 null 且字符串已经处理完毕了, 那就返回 nullptr

  cout << strtok(s + 1, ")") << ' '; // 025
  // 当 str 传 nullptr 的时候, str 默认就是上一次调用的时候改成 \0
  // 的区域后面的位置
  cout << strtok(nullptr, "-") << ' '; // 87234865

  cout << strtok(nullptr, "\0") << ' '; // 987
  // cout << strtok(nullptr, "");   // 987
  // cout << (strtok(nullptr, "") == nullptr); // 987
  return 0;
}
