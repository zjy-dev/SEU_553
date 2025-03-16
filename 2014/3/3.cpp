#include <bits/stdc++.h>
using namespace std;

void my_swap1(int *arr, size_t size, int m, int n) {
  // 如果可以分配额外空间
  int temp[size], pos = 0;
  for (size_t i = size - n; i < size; i++)
    temp[pos++] = arr[i];
  for (size_t i = m; i < size - n; i++)
    temp[pos++] = arr[i];
  for (size_t i = 0; i < m; i++)
    temp[pos++] = arr[i];

  for (size_t i = 0; i < size; i++)
    arr[i] = temp[i];
}

template <typename T> void my_swap(T &a, T &b) {
  T temp;
  temp = a, a = b, b = temp;
}

template <typename T> void my_reverse(T *begin, T *end) {
  --end;
  while (begin < end)
    my_swap(*(begin++), *(end--));
}

void my_swap2(int *arr, size_t size, int m, int n) {
  // 如果不能分配额外空间
  my_reverse(arr + 0, arr + m); // [0, m)
  my_reverse(arr + m, arr + size - n);
  my_reverse(arr + size - n, arr + size);

  my_reverse(arr + 0, arr + size);
}

int main() {
  // my_swap(2, 4)
  // |0 1| |2 3 4| |5 6 7 8|
  // |5 6 7 8| |2 3 4| |0 1|
  // a b c
  // c b a
  // (a-b-)- = ba
  // (a-b-c-)- = c(a-b-)- = c(ba) = cba
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  my_swap1(arr, 9, 2, 4);
  for (size_t i = 0; i < 9; i++)
    cout << arr[i] << " ";
  puts("");

  int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  my_swap2(arr2, 9, 2, 4);
  for (size_t i = 0; i < 9; i++)
    cout << arr2[i] << " ";
  return 0;
}