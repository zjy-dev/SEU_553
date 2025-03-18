#include <bits/stdc++.h>
using namespace std;

bool is_punctuation(char ch) {
  return (ch == ',' || ch == '.' || ch == '!' || ch == '?');
}

char my_tolower(char c) {
  if (c >= 'A' && c <= 'Z')
    return (c - 'A') + 'a';

  return c;
}

void input() {
  ifstream ifs("input.txt");
  string s;
  // hash(任何类型的key) -> 哈希值 -> 具体的表项(任何类型的val)
  map<string, unsigned> m; // 按 key 升序排列
  while (ifs >> s) {
    // abc
    // ,abc
    // abc,def
    string temp("");
    for (size_t i = 0; i < s.size(); i++) {
      if (!is_punctuation(s[i])) {
        temp += my_tolower(s[i]);
        continue;
      }

      if (temp.size() == 0)
        continue;

      // 统计次数
      m[temp]++;

      temp.clear();
    }

    if (temp.size())
      m[temp]++;
  }

  ifs.close();

  // 打印结果
  for (const pair<string, unsigned> &item : m)
    cout << item.first << ": " << item.second << endl;
}

void input2() {
  // i string stream
  // i f      stream
  ifstream ifs("input.txt");
  string s;
  map<string, unsigned> m;

  while (ifs >> s) {
    // abc
    // ,abc
    // abc def
    for (size_t i = 0; i < s.size(); i++) {
      if (is_punctuation(s[i]))
        s[i] = ' ';
      s[i] = my_tolower(s[i]);
    }

    istringstream iss(s);
    string temp;
    while (iss >> temp)
      m[temp] += 1;
  }

  ifs.close();

  // 打印结果
  for (const pair<string, unsigned> &item : m)
    cout << item.first << ": " << item.second << endl;
}

void input3() {
  // TODO: strtok实现
}

int main() {
  // input();
  input2();

  return 0;
}
