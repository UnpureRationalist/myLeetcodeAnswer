#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximumSum(vector<int> &arr) {
    int n = arr.size();
    // 以 i 开头的最大子数组和，对应的状态方程为：f[i] = max( f[i+1] , 0 ) + arr[i]
    vector<int> dp(n + 1, -1e9);
    int ans = INT32_MIN;
    for (int i = n - 1; i >= 0; --i) {
      dp[i] = max(dp[i + 1], 0) + arr[i];
      ans = max(ans, dp[i]);
    }
    int presum = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, presum + dp[i + 1]);  // 删除 arr[i] 的区间最大和
      presum = max(presum, 0) + arr[i];
    }
    return ans;
  }
};
