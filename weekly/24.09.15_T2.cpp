#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maxScore(vector<int> &a, vector<int> &b) {
    long long ans = LONG_MIN;
    int n = b.size();

    vector<vector<long long>> matrix(4, vector<long long>(n, 0));

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < n; ++j) {
        matrix[i][j] = (long long)(a[i]) * b[j];
      }
    }

    vector<vector<long long>> dp(4, vector<long long>(n, LONG_MIN));

    dp[0][0] = matrix[0][0];
    for (int i = 1; i < n; ++i) {
      dp[0][i] = max(dp[0][i - 1], matrix[0][i]);
    }

    for (int row = 1; row < 4; ++row) {
      for (int col = row; col < n; ++col) {
        dp[row][col] = max(dp[row][col - 1], dp[row - 1][col - 1] + matrix[row][col]);
      }
    }

    return dp[3][n - 1];
  }
};