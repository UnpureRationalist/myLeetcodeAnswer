#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> num2idx;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      const auto iter = num2idx.find(target - nums[i]);
      if (iter != num2idx.end()) {
        vector<int> result{iter->second, i};
        return result;
      }
      num2idx.emplace(nums[i], i);
    }
    return {-1, -1};
  }
};
