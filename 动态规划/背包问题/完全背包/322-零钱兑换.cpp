#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    if (amount == 0) {
      return 0;
    }
    int n = coins.size();
    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      int coin = coins[i];
      for (int j = coin; j <= amount; ++j) {
        dp[j] = min(dp[j], dp[j - coin] + 1);
      }
    }
    return dp[amount] == 1e9 ? -1 : dp[amount];
  }
};
