#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int no_zero_idx = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] != 0) {
        nums[no_zero_idx++] = nums[i];
      }
    }
    while (no_zero_idx < n) {
      nums[no_zero_idx++] = 0;
    }
  }
};

class Solution2 {
 public:
  void moveZeroes(vector<int>& nums) {
    int no_zero_idx = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] != 0) {
        swap(nums[i], nums[no_zero_idx]);  // 将非零值和零值交换位置
        no_zero_idx++;
      }
    }
  }
};

class Solution3 {
 public:
  void moveZeroes(vector<int>& nums) {
    // Why not use STL?
    fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
  }
};