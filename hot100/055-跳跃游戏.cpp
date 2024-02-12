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
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int last_idx = n - 1;
    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] >= last_idx - i) {
        last_idx = i;
      }
    }
    return last_idx == 0;
  }
};

class Solution {
 public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int rightmost = 0;
    for (int i = 0; i < n && i <= rightmost; ++i) {
      rightmost = max(rightmost, i + nums[i]);
      if (rightmost >= n - 1) {
        return true;
      }
    }
    return false;
  }
};
