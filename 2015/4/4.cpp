#include <bits/stdc++.h>
using namespace std;

// 只替换第一个
void findRepStr(char str[], const char findStr[], const char replaceStr[]) {
  size_t len = strlen(str), findstr_len = strlen(findStr),
         replacestr_len = strlen(replaceStr);

  char *new_str = new char[len + findstr_len + replacestr_len];

  size_t find_pos = -1;
  for (size_t i = 0; i < len - findstr_len + 1; i++) {
    // 从 i 开始的子字符串是否等于 finsStr
    bool find = true;
    for (size_t j = 0; j < findstr_len; j++) {
      if (str[i + j] != findStr[j]) {
        find = false;
        break;
      }
    }

    if (!find) {
      new_str[i] = str[i];
      continue;
    }

    find_pos = i;
    break;
  }

  if (find_pos == -1) {
    cout << str << endl;
    return;
  }

  for (size_t i = 0; i < replacestr_len; i++) {
    new_str[find_pos + i] = replaceStr[i];
  }

  size_t last_pos = -1;
  for (size_t i = 0; i < len - (find_pos + findstr_len); i++) {
    new_str[find_pos + replacestr_len + i] = str[find_pos + findstr_len + i];
    last_pos = find_pos + replacestr_len + i;
  }

  // 本质上是因为没加法
  // string 的 +

  new_str[last_pos + 1] = '\0';
  cout << new_str << endl;

  string s;
}

int main() {
  char str[] = "Gao m za Enza za acsdf";
  char findStr[] = "za";
  char replaceStr[] = "Van";

  findRepStr(str, findStr, replaceStr);
  return 0;
}
