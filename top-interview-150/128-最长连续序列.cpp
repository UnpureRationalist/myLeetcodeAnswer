#include "header.h"

class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> hash(nums.begin(), nums.end());
    int ans = 0;
    for (const auto &num : hash) {
      if (hash.find(num - 1) == hash.end()) {
        int count = 1;
        while (hash.find(num + count) != hash.end()) {
          ++count;
        }
        ans = max(ans, count);
      }
    }
    return ans;
  }
};
