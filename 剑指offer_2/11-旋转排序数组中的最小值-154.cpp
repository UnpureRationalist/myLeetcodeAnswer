#include "header.h"

class Solution {
  int minInOrder(const vector<int> &nums, int low, int high) {
    int ans = nums[low];
    for (int i = low + 1; i <= high; ++i) {
      if (nums[i] < ans) {
        ans = nums[i];
      }
    }
    return ans;
  }

 public:
  int findMin(vector<int> &nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int mid = low;
    while (nums[low] >= nums[high]) {
      if (high - low == 1) {
        mid = high;
        break;
      }
      mid = (low + high) / 2;
      // 如果 low, high, mid 三个位置数字相等，则只能顺序查找
      if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
        return minInOrder(nums, low, high);
      }
      if (nums[low] <= nums[mid]) {
        low = mid;
      } else if (nums[mid] <= nums[high]) {
        high = mid;
      }
    }
    return nums[mid];
  }
};
