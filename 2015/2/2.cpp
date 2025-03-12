#include <iostream>
#include <string>
using namespace std;

void dfs(const string &str, size_t pos) {
  int len = str.size();

  // 开区间风格/闭区间风格
  if (pos == len)
    return;

  // 先递归
  dfs(str, pos + 1);

  // 才能打印当前
  if (str[pos] >= '0' and str[pos] <= '9')
    cout << str[pos];
}

int main() {
  string str = "1 x 2 y z 3 d h 4 g 5";
  //   getline(cin, str);
  dfs(str, 0);
  puts("");

  return 0;
}