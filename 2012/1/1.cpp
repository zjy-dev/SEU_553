#include <iostream>
using namespace std;

// 欧几里得递归求最大公约数
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// // 欧几里得迭代求最大公约数
// int gcd2(int a, int b) {
//   int temp;
//   while (b != 0) {
//     temp = a;
//     a = b;
//     b = temp % b;
//   }
//   return a;
// }

// a, b 最小公倍数的公式
// gcd = (a 和 b的最大公约数)
// ((a % n) * (b % n) / (g % n)) % n
// a / g * b

// 辗转相除法
int main() {
  int n1, n2, temp;
  cin >> n1 >> n2;

  temp = gcd(n1, n2);       // 求得最大公约数
  cout << (n1 / temp * n2); // 先除以最大公约数再乘，避免溢出

  return 0;
}