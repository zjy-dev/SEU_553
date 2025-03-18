#include <bits/stdc++.h>
using namespace std;

const size_t THROW_TIME = 1000;

int main() {
  srand(time(nullptr));

  int A[3][THROW_TIME];

  for (int i = 0; i < THROW_TIME; i++) {
    A[0][i] = rand() % 6 + 1, A[1][i] = rand() % 6 + 1;
    A[2][i] = A[0][i] + A[1][i];
  }

  // for (int i = 0; i < THROW_TIME; i++)
  //   cout << A[2][i] << " ";
  // puts("");

  int B[11];
  memset(B, 0, sizeof B);

  for (int i = 0; i < THROW_TIME; i++)
    B[A[2][i] - 2]++;

  int cnt = 0;
  for (int i = 2; i <= 12; i++) {
    cout << "和为 " << i << " 出现的次数为: " << B[i - 2] << endl;
    cnt += B[i - 2];
  }

  assert(cnt == THROW_TIME);
  return 0;
}