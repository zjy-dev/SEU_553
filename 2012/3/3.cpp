#include <bits/stdc++.h>
using namespace std;

bool is_punctuation(char ch) {
  return (ch == ',' || ch == '.' || ch == '!' || ch == '?' || ch == ' ');
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

  // 按照 key 升序排序的哈希表
  map<string, int> str_map;
  // kv: key-value
  // pair<string, int>
  // pair.first, pair.second

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

    // "location,Do"
    string temp("");
    for (size_t i = 0; i < s.size(); i++) {
      if (is_punctuation(s[i])) {
        if (temp.size() != 0)
          str_map[temp]++;
        temp.clear();
        continue;
      }

      temp += tolower(s[i]);
    }
    if (temp.size() != 0)
      str_map[temp]++;

    // "location do"
    // istringstream ss(s);
    // while (ss >> s)
    //   str_map[s]++;

    // cout << s << endl;
  }

  for (auto item : str_map) {
    cout << item.first << ": " << item.second << endl;
  }

  // for (auto it = str_map.begin(); it != str_map.end(); ++it) {
  //   cout << it->first << ": " << (*it).second << endl;
  // }
}

int main() {
  input();

  return 0;
}
