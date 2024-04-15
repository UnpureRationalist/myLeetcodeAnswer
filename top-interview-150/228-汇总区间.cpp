#include "header.h"

class Solution {
 public:
  vector<string> summaryRanges(vector<int> &nums) {
    int n = nums.size();
    vector<string> result;
    int i = 0;
    while (i < n) {
      int j = i + 1;
      while (j < n && nums[j] == nums[j - 1] + 1) {
        ++j;
      }
      if (j == i + 1) {
        result.emplace_back(to_string(nums[i]));
      } else {
        result.emplace_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
      }
      i = j;
    }
    return result;
  }
};
