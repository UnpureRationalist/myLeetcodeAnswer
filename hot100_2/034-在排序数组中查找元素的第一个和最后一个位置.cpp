#include <bits/stdc++.h>
using namespace std;

class Solution {
  int searchFirst(const vector<int> &nums, int target, int low, int high) {
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        if (mid == low || nums[mid - 1] != target) {
          return mid;
        }
        high = mid - 1;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }

  int searchLast(const vector<int> &nums, int target, int low, int high) {
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        if (mid == high || nums[mid + 1] != target) {
          return mid;
        }
        low = mid + 1;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }

 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();
    int idx = searchFirst(nums, target, 0, n - 1);
    if (idx == -1) {
      return {-1, -1};
    }
    return {idx, searchLast(nums, target, idx, n - 1)};
  }
};
