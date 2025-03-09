﻿#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

//     j
// 1 2 3 4 5
// 5 1 3 2 4
// 1 2 3 4 5
// 迭代插入排序
// 迭代 = 循环
template <typename T> void insert_sort(vector<T> &arr) {
  int n = arr.size();

  for (int i = 1; i < n; i++)
    for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
      swap(arr[j], arr[j + 1]);
    }
}

// 递归插入排序

// 把 [i, n - 1] 都排好序
// 把 i 这个位置插入到前面的有序序列中
// arr(i + 1), 把 [i + 1, n - 1] 都排好序
template <typename T> void insert_recursive(vector<T> &arr, int i, int n) {
  if (i == n)
    return;

  for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
    swap(arr[j], arr[j + 1]);
  }

  // 递归处理下一个元素
  insert_recursive(arr, i + 1, n);
}

int main() {

  // 递推
  vector<int> arr(20);
  for (int i = 0; i < 20; ++i) {
    arr[i] = rand() % 100;
  }
  insert_sort<int>(arr);

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