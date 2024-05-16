#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        dp[i] = nums[i];
      } else if (i == 1) {
        dp[i] = max(nums[0], nums[1]);
      } else {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
