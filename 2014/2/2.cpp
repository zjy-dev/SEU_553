#include <bits/stdc++.h>
using namespace std;

char *int_to_str(int a) {
  // '-' 不需要'+'
  // new 多少长度?
  // 考试多用三目和 ','
  // 平时编程恰恰相反
  size_t len = a < 0 ? 1 : 0;

  int temp = a;
  while (temp)
    temp /= 10, len++;

  // 运行时在堆区动态分配空间, new 出来的空间全是 0 == '\0'
  // s[len] == '\0'
  char *s = new char[len + 1];
  s[len] = '\0', s[0] = '-';

  // 分配好了, 塞数据
  temp = a > 0 ? a : -a; // 尽量别动形参, 你不知道最后会不会用到!!!
  for (size_t i = len - 1; temp; i--)
    s[i] = temp % 10 + '0', temp /= 10;

  return s;
}

int main() {
  char *p = int_to_str(-12345);
  cout << p << endl, delete[] p;

  p = int_to_str(12345);
  cout << p << endl, delete[] p;
  return 0;
}