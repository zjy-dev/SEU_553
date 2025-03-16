#include <iostream>
#include <vector>

using namespace std;

void find_saddle_points(const vector<vector<int>> &arr) {
  int row = arr.size();
  int col = arr[0].size();
  // 如果不重的话, 最多 row 个

  for (int i = 0; i < row; i++) {
    // 找到当前行的最大值所在列标
    int col_idx = 0;
    for (int j = 1; j < col; j++)
      if (arr[i][j] > arr[i][col_idx])
        col_idx = j;

    // 检查该元素是否是所在列的最小值
    bool is_saddle_point = true;
    for (int r = 0; r < row; r++) {
      // r == i
      if (arr[r][col_idx] < arr[i][col_idx]) {
        is_saddle_point = false;
        break;
      }
    }

    if (is_saddle_point)
      cout << "鞍点: (" << i << "," << col_idx << ") -> " << arr[i][col_idx]
           << endl;
  }
}

int main() {
  // 03 08 07
  // 09 11 13
  // 15 16 17
  vector<vector<int>> matrix = {{3, 8, 7}, {9, 11, 13}, {15, 16, 17}};

  find_saddle_points(matrix);
  return 0;
}
