﻿/*程序功能较简单，直接使用头文件与内联函数完成*/
#include "Car.h"
#include <iostream>
using namespace std;

int main() {
  Car c("123", "BMW", 100);
  c.showInfo();

  return 0;
}
