#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumOperations(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<unordered_map<int, int>> num2counts(cols);
    for (int col = 0; col < cols; ++col) {
      for (int row = 0; row < rows; ++row) {
        num2counts[col][grid[row][col]]++;
      }
    }
    vector<vector<int>> dp(cols, vector<int>(10, INT_MAX));
    // 初始化 dp 数组第 0 行
    for (int i = 0; i < 10; ++i) {
      dp[0][i] = rows - num2counts[0][i];
    }
    // 递推
    for (int col = 1; col < cols; ++col) {
      for (int num = 0; num < 10; ++num) {
        for (int last_col_num = 0; last_col_num < 10; ++last_col_num) {
          if (num != last_col_num) {
            dp[col][num] = min(dp[col][num], dp[col - 1][last_col_num] + rows - num2counts[col][num]);
          }
        }
      }
    }
    // 返回 dp[cols - 1] 最小值即可
    int ans = dp[cols - 1][0];
    for (int i = 1; i < 10; ++i) {
      ans = min(ans, dp[cols - 1][i]);
    }
    return ans;
  }
};