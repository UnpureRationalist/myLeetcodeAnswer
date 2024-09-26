#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int no_zero_idx = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] != 0) {
        nums[no_zero_idx++] = nums[i];
      }
    }
    for (int i = no_zero_idx; i < n; ++i) {
      nums[i] = 0;
    }
  }
};
