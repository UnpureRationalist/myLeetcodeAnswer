#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool subsetSumTarget(const vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = target; j >= nums[i - 1]; --j) {
        dp[j] = dp[j] || dp[j - nums[i - 1]];
      }
    }
    return dp[target];
  }

 public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;  // 所有元素和为奇数，必然不能分割成两个和相等的子集，直接返回 false
    }
    int target = sum / 2;  // 问题转化为：在 nums 中选择若干个元素，使得元素之和为 target
    return subsetSumTarget(nums, target);
  }
};
