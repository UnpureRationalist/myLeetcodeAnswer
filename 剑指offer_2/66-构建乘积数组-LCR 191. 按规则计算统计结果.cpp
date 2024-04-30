#include "header.h"

class Solution {
 public:
  vector<int> statisticalResult(vector<int> &nums) {
    int n = nums.size();
    if (n <= 0) {
      return {};
    }
    vector<int> result(n, 1);
    // result 数组先保存前缀乘积结果 result[i] 表示 [0, i - 1] 乘积结果
    for (int i = 1; i < n; ++i) {
      result[i] = result[i - 1] * nums[i - 1];
    }
    int lastMult = nums.back();
    for (int i = n - 2; i >= 0; --i) {
      result[i] = result[i] * lastMult;
      lastMult *= nums[i];
    }
    return result;
  }
};
