#include "header.h"

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> value2idx;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int num = nums[i];
      if (value2idx.find(num) != value2idx.end()) {
        int idx = value2idx[num];
        if (i - idx <= k) {
          return true;
        }
      }
      value2idx[num] = i;
    }
    return false;
  }
};
