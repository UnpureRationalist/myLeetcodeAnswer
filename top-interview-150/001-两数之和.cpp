#include "header.h"

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();
    unordered_map<int, int> value2idx;
    for (int i = 0; i < n; ++i) {
      if (value2idx.find(target - nums[i]) != value2idx.end()) {
        return {value2idx[target - nums[i]], i};
      }
      value2idx[nums[i]] = i;
    }
    return {-1, -1};
  }
};
