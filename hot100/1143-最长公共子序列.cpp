#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = text1[0] == text2[0];
    for (int col = 1; col < n; ++col) {
      dp[0][col] = max(dp[0][col - 1], static_cast<int>(text1[0] == text2[col]));
    }
    for (int row = 1; row < m; ++row) {
      dp[row][0] = max(dp[row - 1][0], static_cast<int>(text1[row] == text2[0]));
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = max(dp[i - 1][j - 1] + static_cast<int>(text1[i] == text2[j]), max(dp[i - 1][j], dp[i][j - 1]));
      }
    }
    return dp[m - 1][n - 1];
  }
};

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
      char c1 = text1.at(i - 1);
      for (int j = 1; j <= n; j++) {
        char c2 = text2.at(j - 1);
        if (c1 == c2) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};
