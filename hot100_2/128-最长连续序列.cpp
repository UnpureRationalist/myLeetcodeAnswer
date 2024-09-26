#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    int ans = 0;
    unordered_set<int> st(nums.begin(), nums.end());
    for (const auto &num : nums) {
      if (st.find(num - 1) == st.end()) {
        int count = 1;
        int tmp = num;
        while (st.find(++tmp) != st.end()) {
          ++count;
        }
        ans = max(ans, count);
      }
    }
    return ans;
  }
};
