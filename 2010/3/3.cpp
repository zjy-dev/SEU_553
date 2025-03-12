#include <bits/stdc++.h>
using namespace std;

// 朴素算法
// 没有什么特定的思路, en写
void solve(const string &s) {

  // "(010)(15012345678)|123|(430070)"
  size_t len = s.size();

  // 当你在循环体里更新了 i 的时候
  // 你就别用 for 循环了
  // 老老实实用 while
  int i = 0;
  while (i < len) {

    if (s[i] == '(' || s[i] == '|') {
      i++;
      string temp("");
      while (s[i] != ')' && s[i] != '|')
        temp += s[i++];

      cout << temp;

      if (i != len - 1)
        cout << '|';
      i++;
    }
  }

  // puts("");
  cout << endl;
}

int main() {

  // ifs 是一个输入流, 输入流都有一个源头
  // ifs 的源头是不是 info.txt
  ifstream ifs("info.txt");
  string line;

  // 读不到就返回 nullptr
  // getline(ifs, line);
  // ifs -> line
  while (getline(ifs, line)) {
    // cout << line << endl;
    solve(line);
  }

  return 0;
}
