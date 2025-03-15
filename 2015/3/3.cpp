#include <bits/stdc++.h>
using namespace std;

int main() {
  srand(time(nullptr));
  const int THROW_TIME = 1000;

  unsigned A[3][THROW_TIME];

  for (int i = 0; i < THROW_TIME; i++) {
    unsigned first = rand() % 6 + 1, second = rand() % 6 + 1;
    A[0][i] = first, A[1][i] = second;
    A[2][i] = first + second;
  }

  unsigned B[11];
  memset(B, 0, sizeof B);
  for (int i = 0; i < THROW_TIME; i++)
    B[A[2][i] - 2]++;

  int sum_cnt = 0;
  for (int i = 2; i <= 12; i++) {
    printf("和值 %d 出现的次数: %d\n", i, B[i - 2]);
    sum_cnt += B[i - 2];
  }

  assert(sum_cnt == THROW_TIME);

  return 0;
}