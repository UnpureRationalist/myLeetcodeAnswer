#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    int zeroCount = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      zeroCount += nums[r] == 0;
      while (l < n && zeroCount > 1) {
        if (nums[l] == 0) {
          --zeroCount;
        }
        ++l;
      }
      ans = max(ans, r - l);
    }
    return ans;
  }
};
