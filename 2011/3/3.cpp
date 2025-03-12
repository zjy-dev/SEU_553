#include <bits/stdc++.h>
using namespace std;

// 返回 arr[pos, n) 中最小值的下标
// [pos + 1, n) 中的最小值下标
// 和 arr[pos] 比一下
int getMin(int *arr, int n, int pos) {

  // 递归的终点实际上是状态转移的起点
  // [n - 1, n)
  if (pos == n - 1)
    return pos;

  // 假设已经知道了 [pos + 1, n) 的最小值了
  // [pos + 1, n) ---> [pos, n)
  size_t min_pos = getMin(arr, n, pos + 1);
  int min_val = arr[min_pos];

  return arr[pos] < min_val ? pos : min_pos;
}

int main() {
  // 如果你这个函数返回最小值, 那你要额外记录下标
  // 如果你这个函数返回最小值下标
  int arr[10];
  for (int i = 0; i < 10; ++i) {
    arr[i] = rand() % 1000;
  }

  for (int i = 0; i < 10; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;

  int min_pos = getMin(arr, 10, 0);
  cout << min_pos << " " << arr[min_pos] << endl;

  // dfs 和 dp 互转, 实际上就是 dfs(i) 和 dp[i] 的含义保持一致

  // 起点 + 状态转移 + 想明白怎么出答案
  // dp[i] 代表 arr[0, i] 最小值下标
  // 起点: dp[0] = 0
  // 状态转移: dp[i + 1] = (arr[i] < arr[dp[i - 1]] ? i : dp[i - 1])
  // ans: dp[n - 1]

  // dp[i] = 如果 arr[dp[i - 1]] < arr[i] ? dp[i - 1] : i
  int dp[15];
  dp[0] = 0;

  for (int i = 1; i < 10; i++) {
    if (arr[i] < arr[dp[i - 1]]) {
      dp[i] = i;
      continue;
    }
    dp[i] = dp[i - 1];
  }

  cout << dp[9] << " " << arr[dp[9]] << endl;
  return 0;
}