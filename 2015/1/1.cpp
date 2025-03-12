#include <cmath> //增加fabs头文件
#include <iomanip>
#include <iostream>
using namespace std;

double myExp(double x) {
  double ans = 0, item = 1;
  double fenmu = 1, old;

  do {
    ans += item;
    old = item;
    item *= x / (fenmu++);
  } while (fabs(old - item) > 10e-10);

  return ans;
}

int main() {
  double x = 1.5;

  //  这两个一起用就可以操纵小数点后 n 位了
  // fixed: 接下来设置小数点后几位
  // setprecision: 有效数字长度, 3.14(3位)

  // 结合起来就是小数点后 n 位了
  cout << fixed << setprecision(10) << myExp(x) << endl;

  return 0;
}