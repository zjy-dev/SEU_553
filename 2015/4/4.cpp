#include <bits/stdc++.h>
using namespace std;

// 只替换第一个
void findRepStr(char str[], const char findStr[], const char replaceStr[]) {
  size_t len = strlen(str), findstr_len = strlen(findStr),
         replacestr_len = strlen(replaceStr);

  vector<size_t> v;

  for (size_t i = 0; i <= len - findstr_len; i++) {
    bool found = true;
    for (size_t j = 0; j < findstr_len; j++)
      if (str[i + j] != findStr[j])
        found = false;
    if (found)
      v.push_back(i);
  }

  // 我要这个完整的字符串, \0 呢????
  char ans[len + v.size() * (replacestr_len - findstr_len) + 1];
  ans[len + v.size() * (replacestr_len - findstr_len)] = '\0';

  // 3 5 8
  // for (size_t i = 0; i < v.size(); i++) {
  //   auto pos = v[i];
  // }
  // for (auto pos : v) {
  // }
  size_t ori_pos = 0, ans_pos = 0;
  for (auto pos : v) {
    while (ori_pos < pos)
      ans[ans_pos++] = str[ori_pos++];

    for (size_t i = 0; i < replacestr_len; i++)
      ans[ans_pos++] = replaceStr[i];

    ori_pos += findstr_len;
  }

  while (ori_pos < len)
    ans[ans_pos++] = str[ori_pos++];

  assert(ans_pos == len + v.size() * (replacestr_len - findstr_len));

  cout << ans << endl;
}

int main() {
  char str[] = "Gao m za Enza za acsdfza";
  char findStr[] = "za";
  char replaceStr[] = "Van";
  // "Gao m Van Enza Van acsdf";
  findRepStr(str, findStr, replaceStr);
  return 0;
}
