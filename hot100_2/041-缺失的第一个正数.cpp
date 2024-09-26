#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    // 标记不在 [1, n] 的数为 n+1
    for (auto &elem : nums) {
      if (elem < 1 || elem > n) {
        elem = n + 1;
      }
    }
    // 遍历 nums 数组，对每个元素 x，其原值为 |x|，如果
    // ∣x∣∈[1,N]，那么我们给数组中的第 ∣x∣−1 个位置的数添加一个负号
    for (int i = 0; i < n; ++i) {
      int x = abs(nums[i]);
      if (x >= 1 && x <= n) {
        if (nums[x - 1] > 0) {
          nums[x - 1] = -nums[x - 1];
        }
      }
    }
    // 找到 nums 中第一个大于 0 的位置 i，则 i+1 在原 nums 数组中未出现
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }
    return n + 1;
  }
};
