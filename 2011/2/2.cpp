#include <cmath> //fabs头文件
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double cnt = 1, ans = 0, item_abs = 4, sign = 1;

  while (item_abs > 1e-8) {
    ans += item_abs * sign;

    // 更新
    sign *= -1, item_abs = 4 / (cnt += 2);
  }
  cout << fixed << setprecision(10) << ans;

  return 0;
}