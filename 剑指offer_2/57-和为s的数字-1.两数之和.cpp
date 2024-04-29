#include "header.h"

// Leetcode 1. 两数之和
class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> num2idx;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (num2idx.find(target - nums[i]) != num2idx.end()) {
        return {num2idx[target - nums[i]], i};
      }
      num2idx[nums[i]] = i;
    }
    return {-1, -1};
  }
};

// 剑指 offer：排序数组 双指针即可