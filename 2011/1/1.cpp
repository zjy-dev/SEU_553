#include <cmath> //增加fabs头文件
#include <iomanip>
#include <iostream>
using namespace std;

double myExp(double x) {
  // 答案有无数种
  double ans = 0, item = 1, cnt = 0;

  // abs 求整数绝对值
  // fabs 求浮点数绝对值
  while (fabs(item) > 1e-10) {
    ans += item;

    // 更新 item
    // 规则是 分子 *= x, 然后分母 *= cnt, 再然后 cnt++
    // 考试的时候多写 ',', 把问题在一行里解决
    item *= (x / ++cnt);
  }

  return ans;
}

int main() {
  double x = 1;

  //  这两个一起用就可以操纵小数点后 n 位了
  // fixed: 接下来设置小数点后几位
  // setprecision: 有效数字长度, 33.14(2位)

  // 结合起来就是小数点后 n 位了
  cout << fixed << setprecision(10) << myExp(x) << endl;
  return 0;
}
