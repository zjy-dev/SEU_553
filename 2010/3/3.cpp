#include <bits/stdc++.h>
using namespace std;

void solve(const string &s) {

  size_t len = s.size();
  int i = 0;

  while (i < len) {
    // 当 body 里面修改了 i
    // 老老实实用 while

    if (s[i] == '(' || s[i] == '|') {
      // 跳过了 (
      i++;
      string temp = "";
      while (s[i] != ')' && s[i] != '|') {
        if (s[i] == ' ') {
          i++;
          continue;
        }

        temp += s[i++];
      }

      // i 指向 )
      cout << temp;
      if (i != len - 1)
        cout << "|";
      i++;
      continue;
    }

    i++;
  }

  puts("");
}

int main() {

  // cin istream对象
  // cout ostream对象
  // istream 的子类 ifstream

  ifstream ifs("info.txt");
  string line;
  while (getline(ifs, line)) {
    // cout << line << endl;
    solve(line);
  }

  return 0;
}
