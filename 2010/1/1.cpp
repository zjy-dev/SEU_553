#include <bits/stdc++.h>
using namespace std;

int main() {
  const int n = rand() % 100;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 1000;

  // 打开流
  // append: 追加
  // trunc: 摧毁重建
  ofstream ofs("data.txt", ios::trunc);

  // 显然 ofstream 是 ostream 的子类

  // 循环 n 个随机数
  for (int i = 0; i < n; i++) {
    int val = arr[i];

    string temp("");
    // 把 val 转换成二进制字符串并写入文件中
    while (val) {
      // 低位
      temp = char('0' + (val % 2)) + temp;
      val /= 2;
    }
    ofs << arr[i] << "的二进制表示为: " << temp << endl;
  }

  // 关闭流
  ofs.close();
  return 0;
}