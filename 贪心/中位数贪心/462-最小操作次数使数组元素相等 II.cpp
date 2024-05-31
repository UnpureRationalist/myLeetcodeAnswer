#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minMoves2(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int target = nums[n / 2];
    int ans = 0;
    for (const auto &num : nums) {
      ans += abs(num - target);
    }
    return ans;
  }
};
