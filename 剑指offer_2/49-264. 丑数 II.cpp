#include "header.h"

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp(n, 1);
    int next_idx = 1;
    int mult2idx = 0;
    int mult3idx = 0;
    int mult5idx = 0;
    while (next_idx < n) {
      int min_value = min(min(dp[mult2idx] * 2, dp[mult3idx] * 3), dp[mult5idx] * 5);
      dp[next_idx++] = min_value;
      while (dp[mult2idx] * 2 <= min_value) {
        ++mult2idx;
      }
      while (dp[mult3idx] * 3 <= min_value) {
        ++mult3idx;
      }
      while (dp[mult5idx] * 5 <= min_value) {
        ++mult5idx;
      }
    }
    return dp[n - 1];
  }
};

// dp
class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
      int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
      dp[i] = min(min(num2, num3), num5);
      if (dp[i] == num2) {
        p2++;
      }
      if (dp[i] == num3) {
        p3++;
      }
      if (dp[i] == num5) {
        p5++;
      }
    }
    return dp[n];
  }
};
