#include "header.h"

// 动态规划
class Solution {
 public:
  int integerBreak(int n) {
    if (n <= 3) {
      return n - 1;
    }
    vector<int> dp(n + 1, 1);
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; ++i) {
      for (int sub_len = 1; sub_len <= i / 2; ++sub_len) {
        dp[i] = max(dp[i], dp[sub_len] * dp[i - sub_len]);
      }
    }
    return dp[n];
  }
};

// 贪心
class Solution {
 public:
  int integerBreak(int n) {
    if (n <= 3) {
      return n - 1;
    }
    // n >= 4
    int timesOf3 = n / 3;  // 能剪成 3 的段数
    // 剩余长度为 4 时，不能减去 3 ，而应该是 2+2
    if (timesOf3 * 3 + 1 == n) {
      timesOf3--;
    }
    int timesOf2 = (n - timesOf3 * 3) / 2;
    return pow(3, timesOf3) * pow(2, timesOf2);
  }
};
