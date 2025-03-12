#include <bits/stdc++.h>
using namespace std;

char *int_to_str(int a) {

  // 123 -> "123"
  // -123 -> "-123"
  // 考试多用 三目
  size_t len = a < 0 ? 1 : 0;

  int t(a);
  while (t) {
    // 考试多用',', 少换行
    t /= 10, len++;
  }

  // a 的十进制位数 + 1(\0)
  // 堆区
  char *s = new char[len + 1];
  if (a < 0)
    s[0] = '-';
  a = abs(a);
  s[len] = '\0';

  // 填充 s
  for (int i = len - 1; a; i--)
    s[i] = '0' + (a % 10), a /= 10;

  return s;
}

int main() {
  char *p = int_to_str(-12345);

  cout << p << endl;
  delete[] p, p = int_to_str(12345);
  cout << p << endl;
  delete[] p;
  return 0;
}