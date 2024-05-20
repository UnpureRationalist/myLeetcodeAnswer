#include <bits/stdc++.h>
using namespace std;

class Solution {
  int maxSubsetSumLessEqualTarget(const vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> dp(target + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    return dp[target];
  }

 public:
  // 参考题解：https://leetcode.cn/problems/last-stone-weight-ii/solutions/818362/gong-shui-san-xie-xiang-jie-wei-he-neng-jgxik/
  // 转换为 01 背包问题，可采用 Leetcode 494 目标和 类似算法求解
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    int max_subset_sum = maxSubsetSumLessEqualTarget(stones, target);
    return sum - 2 * max_subset_sum;
  }
};
