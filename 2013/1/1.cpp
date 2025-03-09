#include <bits/stdc++.h>
using namespace std;

int main() {
  // not_prime[i] == true
  // i 不是素数
  bool not_prime[20000 + 10];
  memset(not_prime, 0, sizeof not_prime);

  for (unsigned i = 2; i <= 20000; i++) {
    if (!not_prime[i]) {
      cout << i << ' ';

      // 筛掉所有的倍数
      for (unsigned j = i + i; j <= 20000; j += i) {
        not_prime[j] = true;
      }
    }
  }

  // [0, n]
  // O(n**1.5), 朴素

  // 近似 O(n), 真的好写, 埃氏筛
  // 思路:
  // 每一个素数的任意倍数都不是素数
  // 我知道一些小的素数, 可以通过它们排除掉很多大的非素数
  // 当我从第一个素数开始筛的时候, 我就能排除所有的非素数!!!
  // 具体怎么个筛
  // bool not_prime[20000 + 10];

  // O(n), 真的难背, 线性筛
  return 0;
}
