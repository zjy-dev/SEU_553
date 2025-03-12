#include <cmath> //增加fabs头文件
#include <iomanip>
#include <iostream>
using namespace std;

double myExp(double x) {
  double ans = 0, item = 1;
  double fenmu = 1;

  // abs: absolute
  // f: float
  // abs(-5)
  while (fabs(item) > 10e-10) { // 使用fabs 指数可以为负
    ans += item;

    // 更新 item
    item *= x / (fenmu++);
  }

  return ans;
}

int main() {
  double x = 1;

  //  这两个一起用就可以操纵小数点后 n 位了
  // fixed: 接下来设置小数点后几位
  // setprecision: 有效数字长度, 3.14(3位)

  // 结合起来就是小数点后 n 位了
  cout << fixed << setprecision(10) << myExp(x) << endl;

  return 0;
}