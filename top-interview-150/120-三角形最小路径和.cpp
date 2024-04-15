#include "header.h"

class Solution {
 public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = dp[i - 1][0] + triangle[i][0];
      dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
      for (int j = 1; j < i; ++j) {
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
      }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};

class Solution {
 public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<int> dp = triangle.back();
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
      }
    }
    return dp[0];
  }
};
