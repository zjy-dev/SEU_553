#include "Array.h"
#include <iostream>
using namespace std;

void func(int a, int b);

int main() {
  Array<int> chess(4, 3);

  func(3, 4);
  chess(3, 4); // 一个对象的 () 运算符, 长得像函数, 仿函数, 只能用成员函数重载

  // cout << chess << endl << endl;
  // for (int i = 0; i < 4; ++i) {
  //   for (int j = 0; j < 3; ++j)
  //     chess(i, j) = j;
  // }
  // cout << chess;

  // Array<int> arr(4, 3);

  return 0;
}