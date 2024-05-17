#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);  // dp[i] 表示以 i 结尾的连续子数组最大和
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      if (dp[i - 1] > 0) {
        dp[i] = dp[i - 1] + nums[i];
      } else {
        dp[i] = nums[i];
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int preSum = 0;
    int ans = nums[0];
    for (auto &num : nums) {
      preSum = max(preSum + num, num);
      ans = max(ans, preSum);
    }
    return ans;
  }
};
