#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int ans = nums.front();
    int preSum = 0;
    for (const auto &num : nums) {
      preSum = max(preSum + num, num);
      ans = max(ans, preSum);
    }
    return ans;
  }
};
