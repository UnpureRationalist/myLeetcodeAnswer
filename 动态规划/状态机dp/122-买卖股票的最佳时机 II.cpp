#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      ans += max(0, prices[i] - prices[i - 1]);
    }
    return ans;
  }
};

// 采用原始状态机 dp 的代码
// dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润；
// dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int dp[n][2];
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
  }
};
