#include "header.h"

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int preSum = 0;
    int ans = nums[0];
    for (auto &num : nums) {
      preSum = max(preSum + num, num);
      ans = max(ans, preSum);
    }
    return ans;
  }
};
