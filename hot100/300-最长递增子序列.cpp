#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);  // dp[i] 表示选取 [0, i] 的 LIS，且 nums[i] 必须被选取
    int ans = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    int len = 1, n = (int)nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] > d[len]) {
        d[++len] = nums[i];
      } else {
        int l = 1, r = len, pos = 0;  // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (d[mid] < nums[i]) {
            pos = mid;
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
        d[pos + 1] = nums[i];
      }
    }
    return len;
  }
};
