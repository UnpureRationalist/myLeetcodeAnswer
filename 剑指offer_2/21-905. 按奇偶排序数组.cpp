#include "header.h"

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    int n = nums.size();
    int even_idx = 0;
    for (int i = 0; i < n; ++i) {
      if ((nums[i] & 1) == 0) {
        swap(nums[i], nums[even_idx]);
        ++even_idx;
      }
    }
    return nums;
  }
};

// 双指针写法
class Solution {
 public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      while (left < right && nums[left] % 2 == 0) {
        left++;
      }
      while (left < right && nums[right] % 2 == 1) {
        right--;
      }
      if (left < right) {
        swap(nums[left++], nums[right--]);
      }
    }
    return nums;
  }
};