﻿#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  ofstream out("table.dat", ios::trunc);
  if (!out)
    return -1; // 文件打开失败

  out << setw(6) << "ASCII" << setw(4) << "dec" << setw(4) << "oct" << setw(4)
      << "hex" << endl;
  for (int i = 33; i <= 126; ++i) {
    out << setw(6) << static_cast<char>(i) << setw(4) << dec << i << setw(4)
        << oct << i << setw(4) << hex << i << endl;
  }

  out.close();

  return 0;
}
