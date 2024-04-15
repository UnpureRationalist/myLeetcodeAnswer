#include "header.h"

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();

    // 有一个字符串为空串
    if (n * m == 0) {
      return n + m;
    }

    // DP 数组
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // 边界状态初始化
    for (int i = 0; i <= n; i++) {
      dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
      dp[0][j] = j;
    }

    // 计算所有 DP 值
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int left = dp[i - 1][j] + 1;
        int down = dp[i][j - 1] + 1;
        int left_down = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
        dp[i][j] = min(left, min(down, left_down));
      }
    }
    return dp[n][m];
  }
};
