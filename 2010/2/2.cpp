#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// 前面的局部先有序
//         i
//
// 1 2 3 5
// 5 1 3 2 4

// 迭代插入排序
// 迭代 = 循环
template <typename T> void insert_sort(vector<T> &arr) {
  int n = arr.size();

  // 最短实现
  for (int i = 1; i < n; i++)
    for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
      swap(arr[j], arr[j + 1]);
}

// 递归插入排序

// 把 [i, n - 1] 都排好序
// 先把 arr[i] 插到前面的有序序列中去
// 再递归的把 [i + 1, n - 1] 排好序
template <typename T> void insert_recursive(vector<T> &arr, int cur, int size) {
  if (cur == size)
    return;

  for (int j = cur - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
    swap(arr[j], arr[j + 1]);

  // 递归处理下一个元素
  insert_recursive(arr, cur + 1, size);
}

int main() {

  // 递推
  vector<int> arr(20);
  for (int i = 0; i < 20; ++i) {
    arr[i] = rand() % 100;
  }
  // 自动推断
  insert_sort(arr);

  for (auto elem : arr)
    cout << elem << " ";
  puts("");

  // 递归
  for (int i = 0; i < 20; ++i) {
    arr[i] = rand() % 100;
  }

  insert_recursive(arr, 0, arr.size());

  for (auto elem : arr)
    cout << elem << " ";

  return 0;
}