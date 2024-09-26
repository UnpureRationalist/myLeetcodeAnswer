#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool check(const vector<int> &nums, int target) {
    int n = nums.size();
    vector<char> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = dp[j] || dp[j - nums[i]];
      }
    }
    return dp[target];
  }

 public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) {
      return false;
    }
    return check(nums, sum / 2);
  }
};
