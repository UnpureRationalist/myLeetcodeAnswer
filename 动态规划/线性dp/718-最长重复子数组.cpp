#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    // dp[i][j] 表示 nums1[0:i] 与 nums2[0:j] 的最长公共子数组长度
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          ans = max(ans, dp[i][j]);
        }
      }
    }
    return ans;
  }
};
