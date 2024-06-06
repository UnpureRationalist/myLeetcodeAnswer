#include <bits/stdc++.h>
using namespace std;

class Solution {
  int digitCount[32];

 public:
  int findKOr(vector<int> &nums, int k) {
    memset(digitCount, 0, sizeof(digitCount));
    for (const auto &num : nums) {
      for (int i = 0; i < 32; ++i) {
        digitCount[i] += (num >> i) & 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      if (digitCount[i] >= k) {
        ans |= (1 << i);
      }
    }
    return ans;
  }
};
