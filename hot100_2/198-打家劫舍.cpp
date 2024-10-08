#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 0);  // dp[i] 表示偷前 i 个店的最大收益
    dp[1] = nums[0];
    for (int i = 1; i < n; ++i) {
      dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
    }
    return dp[n];
  }
};
