#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    for (int i = 1; i < n; ++i) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }
    int post_mult = 1;
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = ans[i] * post_mult;
      post_mult = post_mult * nums[i];
    }
    return ans;
  }
};
