#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    dp[0][0] = grid[0][0];
    for (int row = 1; row < rows; ++row) {
      dp[row][0] = dp[row - 1][0] + grid[row][0];
    }
    for (int col = 1; col < cols; ++col) {
      dp[0][col] = dp[0][col - 1] + grid[0][col];
    }
    for (int row = 1; row < rows; ++row) {
      for (int col = 1; col < cols; ++col) {
        dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
      }
    }
    return dp[rows - 1][cols - 1];
  }
};
