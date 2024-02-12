#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  bool sumTarget(vector<int> &nums, int target) {
    int n = nums.size();
    // dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0
    // 个），是否存在一种选取方案使得被选取的正整数的和等于 j
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; ++i) {
      dp[i][0] = true;
    }

    dp[0][nums[0]] = true;
    for (int i = 1; i < n; ++i) {
      int num = nums[i];
      for (int j = 1; j <= target; ++j) {
        if (j < num) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j - num] | dp[i - 1][j];
        }
      }
    }
    return dp[n - 1][target];
  }

 public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;  // 所有元素和为奇数
    }
    int half = sum / 2;
    if (*max_element(nums.begin(), nums.end()) > half) {
      return false;  // 最大元素大于 half
    }
    // 转化为：nums 数组是否存在子集和为 half
    return sumTarget(nums, half);
  }
};
