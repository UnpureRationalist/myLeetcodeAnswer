#include "header.h"

class Solution {
  int searchFirst(const vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int value = nums[mid];
      if (target > value) {
        low = mid + 1;
      } else if (target < value) {
        high = mid - 1;
      } else if (mid == 0 || nums[mid - 1] != target) {
        return mid;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }

  int searchLast(const vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int value = nums[mid];
      if (target > value) {
        low = mid + 1;
      } else if (target < value) {
        high = mid - 1;
      } else if (mid == nums.size() - 1 || nums[mid + 1] != target) {
        return mid;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }

 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    return {searchFirst(nums, target), searchLast(nums, target)};
  }
};
