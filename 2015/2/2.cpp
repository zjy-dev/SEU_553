#include <iostream>
#include <string>
using namespace std;

unsigned dfs(const string &str, size_t pos) {
  int len = str.size();

  // 开区间风格/闭区间风格
  if (pos == len)
    return 0;

  // 先递归
  unsigned pre = dfs(str, pos + 1);

  if (str[pos] >= '0' and str[pos] <= '9')
    return pre * 10 + (str[pos] - '0');

  return pre;
}

int main() {
  string str = "1 x 2 y z 3 d h 4 g 5 a g";
  //   getline(cin, str);
  cout << dfs(str, 0);
  puts("");

  return 0;
}