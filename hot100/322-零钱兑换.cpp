#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    int bound = amount + 1;
    vector<int> dp(amount + 1, bound);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (const auto &coin : coins) {
        if (coin <= i) {
          dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
      }
    }
    return dp[amount] == bound ? -1 : dp[amount];
  }
};
