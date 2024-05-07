#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool canSteal(const vector<int> &nums, int k, int max_money) {
    // 定义 dp[i] 为从前 i 个房间偷取金额不超过 mid 的房间数量，如果最终 f[n] >= k 则满足条件，反之，则不满足条件
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[1] = nums[0] <= max_money;
    for (int i = 1; i < n; ++i) {
      dp[i + 1] = max(dp[i], dp[i - 1] + (nums[i] <= max_money));
    }
    return dp[n] >= k;
  }

 public:
  int minCapability(vector<int> &nums, int k) {
    int n = nums.size();
    int left = *min_element(nums.begin(), nums.end());
    int right = *max_element(nums.begin(), nums.end());
    int ans = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      bool ok = canSteal(nums, k, mid);
      if (ok && !canSteal(nums, k, mid - 1)) {
        ans = mid;
        break;
      }
      if (ok) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};
