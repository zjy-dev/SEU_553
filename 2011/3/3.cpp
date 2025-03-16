#include <bits/stdc++.h>
using namespace std;

// 如果你返回下标 -> 同时也有了最小值
// 如果你返回最小值 -> 没有下标

// dfs(0) -> [0, n) 中的最小值下标
// dfs(pos) -> [pos, n) 中最小值下标
// dfs(0) 它依赖于什么其他状态呢???
// 依赖于 dfs(1), [1, n) 中的最小值下标
// dfs(pos) -> 依赖于 dfs(pos + 1)
// min_pos = dfs(pos + 1)
// arr[pos] 更小, 答案就是 pos
// 否则答案是 min_pos

// 边界是什么???
// pos == n - 1 时, [n - 1, n) 只有一个元素, 那这个元素当然是最小的!!!
int dfs(const int *const arr, const int n, int pos) {
  // 边界, 相当于递推的起点
  if (pos == n - 1)
    return n - 1;

  // 状态怎么转
  int min_pos = dfs(arr, n, pos + 1);
  if (arr[pos] < arr[min_pos])
    return pos;

  return min_pos;
}

int main() {
  // 初始化数组并打印
  int arr[10];
  for (int i = 0; i < 10; ++i) {
    arr[i] = rand() % 1000;
  }

  for (int i = 0; i < 10; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // 递归出答案
  int min_pos = dfs(arr, 10, 0);
  cout << min_pos << " " << arr[min_pos] << endl;

  // dfs 和 dp 互转, 实际上就是 dfs(i) 和 dp[i] 的含义保持一致

  // 起点 + 状态转移 + 想明白怎么出答案
  // dp[i] 代表 arr[0, i] 最小值下标
  // dp[i + 1] 依赖于 dp[i]
  // 起点: dp[0] = 0
  // 状态转移: dp[i] = (arr[i] < arr[dp[i - 1]] ? i : dp[i - 1])
  // ans: dp[n - 1]

  // dp[i] = 如果 arr[dp[i - 1]] < arr[i] ? dp[i - 1] : i
  int dp[15];
  dp[0] = 0;

  for (int i = 1; i < 10; i++)
    dp[i] = (arr[i] < arr[dp[i - 1]]) ? i : dp[i - 1];

  cout << dp[9] << " " << arr[dp[9]] << endl;
  return 0;
}