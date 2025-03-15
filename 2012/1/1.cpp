#include <iostream>
using namespace std;

// 欧几里得递归求最大公约数
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// 辗转相除法
int main() {
  int n1, n2, temp;
  cin >> n1 >> n2;

  temp = gcd(n1, n2); // 求得最大公约数
  cout << n1 / temp * n2;

  return 0;
}