#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long minCost(vector<int> &nums, vector<int> &cost) {
    long long res = 0, sum = accumulate(cost.begin(), cost.end(), 0ll);
    long long num = sum / 2, val = -1, cnt = 0;
    int n = nums.size();
    vector<int> pos(n, 0);
    for (int i = 0; i < n; i++) {
      pos[i] = i;
    }
    sort(pos.begin(), pos.end(), [&](auto &a, auto &b) { return nums[a] < nums[b]; });
    for (int i = 0; i < n; i++) {
      cnt += cost[pos[i]];
      if (cnt > num) {
        val = nums[pos[i]];
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      res += 1ll * cost[i] * abs(nums[i] - val);
    }
    return res;
  }
};
