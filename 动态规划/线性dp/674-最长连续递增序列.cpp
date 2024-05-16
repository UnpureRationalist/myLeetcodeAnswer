#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findLengthOfLCIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);  // dp[i] 表示以 nums[i] 结尾的最长连续递增的子序列长度
    for (int i = 1; i < n; ++i) {
      dp[i] = nums[i] > nums[i - 1] ? dp[i - 1] + 1 : dp[i];
    }
    return *max_element(dp.begin(), dp.end());
  }
};
