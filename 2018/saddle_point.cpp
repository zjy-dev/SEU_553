#include <iostream>
#include <vector>

using namespace std;

void find_saddle_points(const vector<vector<int>> &arr) {
  int row = arr.size();
  int col = arr[0].size();

  // 如果不重的话, 最多 row 个
  for (int i = 0; i < row; i++) {
    int max_pos = 0;
    for (int j = 1; j < col; j++)
      if (arr[i][max_pos] < arr[i][j])
        max_pos = j;

    // 在这一列里最小吗?
    bool is_min = true;
    for (int j = 0; j < row; j++)
      if (arr[j][max_pos] < arr[i][max_pos])
        is_min = false;

    // 打印鞍点
    if (is_min)
      cout << "鞍点: " << i << ", " << max_pos << ": " << arr[i][max_pos]
           << endl;
  }
}

int main() {
  // 鞍点定义: 在行里最大, 在列里最小
  // 03 (08) 07
  // 09 11 13
  // 15 16 17
  vector<vector<int>> matrix = {{3, 8, 7}, {9, 11, 13}, {15, 16, 17}};

  find_saddle_points(matrix);
  return 0;
}
