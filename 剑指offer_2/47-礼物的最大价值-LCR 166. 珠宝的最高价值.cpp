#include "header.h"

class Solution {
 public:
  int jewelleryValue(vector<vector<int>> &frame) {
    int rows = frame.size();
    int cols = frame[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    dp[0][0] = frame[0][0];
    // init
    for (int row = 1; row < rows; ++row) {
      dp[row][0] = dp[row - 1][0] + frame[row][0];
    }
    for (int col = 1; col < cols; ++col) {
      dp[0][col] = dp[0][col - 1] + frame[0][col];
    }
    for (int row = 1; row < rows; ++row) {
      for (int col = 1; col < cols; ++col) {
        dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]) + frame[row][col];
      }
    }
    return dp[rows - 1][cols - 1];
  }
};
