#include <bits/stdc++.h>
using namespace std;

bool is_punctuation(char ch) { // 判断是否是需要转换的符号
  return (ch == ',' || ch == '.' || ch == '!' || ch == '?');
}

// bool isupper();
// bool islower();

// char tolower(char c) {
//   if (islower(c)) {
//     return c;
//   }

//   if (c < 'A' or c > 'Z')
//     throw logic_error("Not A alpha");

//   return 'a' + (c - 'A');
// }

void input() {
  // 哈希表
  // "string" -> any
  // idx = hash(输入) % n

  // 按照 string 排序有序的哈希表
  map<string, int> str_map;

  string s;
  // cin >> 跳过 ' ' \n
  while (cin >> s) {
    if (s.size() == 1 && is_punctuation(s[0]))
      continue;

    // "abcde";
    // for (string::iterator it = s.begin(); it != s.end(); it++) {
    //   if (is_punctuation(*it)) {
    //     *it = ' ';
    //     continue;
    //   }

    //   *it = tolower(*it);
    // }

    for (size_t i = 0; i < s.size(); i++) {
      if (is_punctuation(s[i])) {
        s[i] = ' ';
        continue;
      }

      s[i] = tolower(s[i]);
    }

    // "abc edg"

    istringstream ss(s);
    istream &t = ss;

    while (t >> s)
      str_map[s]++;

    // cout << s << endl;
  }

  // for (const pair<string, int> &item : str_map) {
  //   cout << item.first << ": " << item.second << endl;
  // }

  for (auto it = str_map.begin(); it != str_map.end(); ++it) {
    cout << it->first << ": " << (*it).second << endl;
  }
}

int main() {
  input();
  map<string, int> strMap; // 统计结果

  string line;
  while (getline(cin, line)) { // 每次读取一行
    // 遍历读入的一行字符，修改其中符号和大小写
    for (string::iterator it = line.begin(); it != line.end(); ++it) {
      if (is_punctuation(*it))
        *it = ' ';
      *it = (isupper(*it) ? tolower(*it) : *it);
    }

    istringstream strStream(
        line); // 将读入的字符串转换成字符串流，再逐个提取其中的单词
    string temp;
    while (strStream >> temp)
      ++strMap[temp]; // 单词计数
  }

  for (pair<string, int> item : strMap) {
    cout << item.first << ": " << item.second << endl;
  }

  return 0;
}
