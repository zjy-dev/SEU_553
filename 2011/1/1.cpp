#include <cmath> //增加fabs头文件
#include <iomanip>
#include <iostream>
using namespace std;

double myExp(double x) {
  double ans = 0, item = 1;
  double n = 0;

  while (fabs(item) > 10e-10) { // 使用fabs 指数可以为负
    ans += item;
    item *= x / (++n);
  }

  return ans;
}

int main() {
  double x;
  cin >> x;

  //  这两个一起用就可以操纵小数点后 n 位了
  cout << fixed << setprecision(10) << myExp(x) << endl;

  return 0;
}