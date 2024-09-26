#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int> &nums) {
    int n = nums.size();
    int hash[3] = {0};
    for (const auto &num : nums) {
      hash[num]++;
    }
    int idx = 0;
    for (int i = 0; i < 3; ++i) {
      while (hash[i]--) {
        nums[idx++] = i;
      }
    }
  }
};
