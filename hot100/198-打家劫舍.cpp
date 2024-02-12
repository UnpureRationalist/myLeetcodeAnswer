#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
      return nums[0];
    }
    vector<int> dp(n, 0);  // dp[i] 表示偷 [0, i) 能获取的最大金额
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
      dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n - 1];
  }
};

class Solution {
 public:
  int rob(vector<int> &nums) {
    int prev = 0;
    int curr = 0;

    // 每次循环，计算 偷到当前房子为止的最大金额
    for (int num : nums) {
      // 循环开始时，curr 表示 dp[k-1]，prev 表示 dp[k-2]
      // dp[k] = max{ dp[k-1], dp[k-2] + i }
      int temp = max(curr, prev + num);
      prev = curr;
      curr = temp;
      // 循环结束时，curr 表示 dp[k]，prev 表示 dp[k-1]
    }

    return curr;
  }
};
