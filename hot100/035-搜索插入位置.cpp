#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high) {
      mid = (low + high) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};

class Solution {
 public:
  int searchInsert(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1, ans = n;
    while (left <= right) {
      int mid = ((right - left) >> 1) + left;
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
