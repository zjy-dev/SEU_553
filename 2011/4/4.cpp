#include <bits/stdc++.h>
using namespace std;

// string arr1[10]
// (const char*) arr2[10]
// (int        ) arr3[10]

void sortOne(string str[], int n) { // 插入排序
  string val;
  for (int i = 1; i < n; ++i) {
    val = str[i];

    // 往有序序列中插入一个新的值
    int j = i;
    // if (val < str[j - 1])
    // 如果用 char *, if (strcmp(val, str[j - 1]) < 0)
    while (j > 0 && val < str[j - 1]) {
      str[j] = str[j - 1];

      // strcmp(s1, s2);
      --j;
    }
    str[j] = val;
  }
}

void sortTwo(string str[], int n) { // 选择排序
  int minPos;
  for (int i = 0; i < n; ++i) {
    minPos = i;

    // 选出一个当前无序序列中的最小值放在有序序列最后面
    for (int j = i + 1; j < n; ++j) {
      if (str[j] < str[minPos])
        minPos = j;
    }
    swap(str[minPos], str[i]);
  }
}

int main() {
  string str[] = {"dsahiubaoas", "asa", "cbasi", "zsaioj"};
  sortOne(str, sizeof(str) / sizeof(str[0]));

  for (auto &elem : str) {
    cout << elem << endl;
  }

  sortTwo(str, sizeof(str) / sizeof(str[0]));
  for (auto &elem : str) {
    cout << elem << endl;
  }

  return 0;
}