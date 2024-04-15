#include "header.h"

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    for (int row = 0; row < rows && obstacleGrid[row][0] == 0; ++row) {
      dp[row][0] = 1;
    }
    for (int col = 0; col < cols && obstacleGrid[0][col] == 0; ++col) {
      dp[0][col] = 1;
    }
    for (int row = 1; row < rows; ++row) {
      for (int col = 1; col < cols; ++col) {
        if (obstacleGrid[row][col] == 0) {
          dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
        }
      }
    }
    return dp[rows - 1][cols - 1];
  }
};
