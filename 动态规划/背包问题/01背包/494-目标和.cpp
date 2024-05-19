#include <bits/stdc++.h>
using namespace std;

class Solution {
  int subsetSumTarget(const vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = target; j >= nums[i - 1]; --j) {
        dp[j] += dp[j - nums[i - 1]];
      }
    }
    return dp[target];
  }

 public:
  /**
   * @brief 给你一个非负整数数组 nums 和一个整数 target 。
   *        向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
   *        例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
   *        返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
   * @attention
   *    本质上相当于把原数组划分为两个不相交的子集（可以为空），记作 S1 和 S2，假设 S1 全部加 + 号；S2 全部加 - 号。
   *    设它们的元素和分别为 A 和 B，整个数组的元素和为 sum。则按照题意，有以下式子联立：
   *        Equation 1： A + B = sum
   *        Equation 2： A - B = target
   *    可以求得 A，B 的结果：A = (sum + target) / 2
   *
   *    于是，问题转化为：在数组 nums 中选取一个子集，使得其元素之和为 (sum + target) / 2 的方案有多少？
   *
   *    可以采用和 Leetcode 416 分割等和子集 类似的思路完成。
   *
   * @param nums 输入数组
   * @param target 目标表达式的值
   * @return int
   */
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0) {
      return 0;  // A 是整数，如果 sum + target 为奇数，必然不存在
    }
    target = (sum + target) / 2;
    if (target < 0) {
      return 0;  // 因为 nums 是非负整数数组，如果 target 为负数，直接返回 0
    }
    return subsetSumTarget(nums, target);
  }
};
