#include <bits/stdc++.h>
using namespace std;

void solve(string &s) {
  int i = 0;
  int size = s.size();

  int cnt = 0;
  while (i < size) {
    if (s[i] == '(' || s[i] == '|') {
      i++;
      string temp = "";
      while (s[i] != ')' and s[i] != '|') {
        temp += s[i++];
      }

      cout << temp;

      cnt++;
      if (cnt <= 3) {
        cout << "|";
      }

      i++;

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
