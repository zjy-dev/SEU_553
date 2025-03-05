#include "Array.h"
#include <iostream>
using namespace std;

void func(int a, int b);

int main() {
  Array<int> chess(4, 3);
  cout << chess << endl << endl;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j)
      chess(i, j) = j;
  }
  cout << chess;

  Array<int> arr(4, 3);

  return 0;
}