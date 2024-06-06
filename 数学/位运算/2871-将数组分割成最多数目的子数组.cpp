#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSubarrays(vector<int> &nums) {
    int count = 0;
    int bit_and = -1;
    for (const auto &num : nums) {
      bit_and &= num;
      if (bit_and == 0) {
        ++count;
        bit_and = -1;
      }
    }
    return count == 0 ? 1 : count;
  }
};
