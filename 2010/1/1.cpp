﻿#include <bits/stdc++.h>
using namespace std;

int main() {
  // 打开流
  ofstream outFile("data.txt", ios::app);

  // 显然 ofstream 是 ostream 的子类

  for (int i = 1; i < 1000; i++) {
    int val = i;
    string s = "";

    while (val) {
      s = char((val % 2) + '0') + s;
      val >>= 1;
    }

    outFile << s << endl;
  }

  // 关闭流
  outFile.close();
  return 0;
}