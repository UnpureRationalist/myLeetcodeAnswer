#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // 找到第一个大于等于 target 的下标
  int searchInsert(vector<int> &nums, int target) {
    int n = nums.size();
    if (n > 0 && nums[0] >= target) {
      return 0;
    }
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (nums[mid] < target) {
        low = mid + 1;
      } else if (mid > 0 && nums[mid] >= target && nums[mid - 1] < target) {
        return mid;
      } else {
        high = mid - 1;
      }
    }
    return n;
  }
};

class Solution {
 public:
  int searchInsert(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1, ans = n;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (target <= nums[mid]) {
        ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};
