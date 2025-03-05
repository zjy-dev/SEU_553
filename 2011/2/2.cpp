#include <cmath> //fabs头文件
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  const double acc =
      10e-10; // 精确到小数点后10位，不清楚计算机可表示的最大范围，请指教
  double fen_mu = 3, ans = 0, item_abs = 4, sign = 1;

  while (item_abs > acc) {
    ans += item_abs * sign;
    sign *= -1;
    item_abs = 4 / fen_mu;
    fen_mu += 2;
  }
  cout << setprecision(10) << ans;

  return 0;
}