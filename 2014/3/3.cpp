#include <bits/stdc++.h>
using namespace std;

// [l, r]
template <typename T> void my_swap(T &a, T &b) {
  T t;
  t = a, a = b, b = t;
}

void my_reverse(int a[], size_t l, size_t r) {
  while (l < r)
    my_swap(a[l++], a[r--]);
}

void solve(int a[], int m, int n, int len) {
  if (m + n > len)
    return;
  // a- -> b- -> c- -> ()-
  // 调用了 stl, reverse(p1, p2)
  // [p1, p2) 取逆
  // |0 1| (2 3) |4 5 6 7 8 9|
  my_reverse(a, 0, m - 1);         // a-
  my_reverse(a, m, len - n - 1);   // b-
  my_reverse(a, len - n, len - 1); // c-

  my_reverse(a, 0, len - 1); // ()-
}

int main() {
  // |0 1| (2 3) |4 5 6 7 8 9|
  // swap(arr, 2, 6)
  // expected:
  // |4 5 6 7 8 9| (2 3) |0 1|
  // abc -> cba
  // (ab)- = b-a-
  // (a-b-c-)- = cba

  // a- -> b- -> c- -> ()-

  // 初始化数组
  int a[10];
  cout << "Before swap: ";
  for (int i = 0; i < 10; ++i) {
    a[i] = i;
    cout << a[i] << ' ';
  }
  cout << endl;

  // swap
  solve(a, 2, 6, 10);
  cout << "After swap:  ";
  for (int elem : a) {
    cout << elem << " ";
  }

  return 0;
}