#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfGoodSubarraySplits(vector<int> &nums) {
    int n = nums.size();
    vector<int> zero_idx;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 1) {
        zero_idx.emplace_back(i);
      }
    }
    int num_zero = zero_idx.size();
    if (num_zero == 0) {
      return 0;
    }
    if (num_zero == 1) {
      return 1;
    }
    int ans = 1;
    const int MOD = 1e9 + 7;
    for (int i = 1; i < num_zero; ++i) {
      ans *= (zero_idx[i] - zero_idx[i - 1]);
      ans = ans % MOD;
    }
    return ans;
  }
};
