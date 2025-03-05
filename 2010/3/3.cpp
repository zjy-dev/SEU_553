#include <bits/stdc++.h>
using namespace std;

void solve(string &s) {
  int i = 0;
  int size = s.size();
  while (i < size) {
    if (s[i] == '(' || s[i] == '|') {
      i++;
      string temp;
      while (i < size && (s[i] != ')' && s[i] != '|')) {
        temp += s[i];
        i++;
      }
      i++;
      cout << temp << " ";
      continue;
    }

    i++;
  }
  cout << endl;
}

int main() {
  ifstream ifs("info.txt");
  string line;
  while (getline(ifs, line)) {
    // cout << line << endl;
    solve(line);
  }
  return 0;
}
