#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSubarray(vector<int> &nums, int p) {
    long long sum = accumulate(nums.begin(), nums.end(), 0ll);
    sum = sum % p;
    if (sum == 0) {
      return 0;
    }

    // 问题转化为：求一个最短的区间长度，使得 区间和%p 的值为 sum%p，如果不存在，返回 -1
    int n = nums.size();
    unordered_map<int, int> sum2idx;
    sum2idx[0] = -1;
    int ans = n;
    // 枚举移除以 i 结尾的子数组
    for (int i = 0, s = 0; i < n; ++i) {
      s = (s + nums[i]) % p;
      int target = (s - sum + p) % p;
      if (sum2idx.count(target)) {
        ans = min(ans, i - sum2idx[target]);
      }
      sum2idx[s] = i;
    }

    return ans == n ? -1 : ans;
  }
};
