#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (const auto &coin : coins) {
        if (i >= coin) {
          dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
      }
    }
    return dp[amount] == 1e9 ? -1 : dp[amount];
  }
};
