#include "header.h"

// Leetcode 179. 最大数
class Solution {
 public:
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](const int i, const int j) -> bool {
      string lop = to_string(i);
      string rop = to_string(j);
      string lr = lop + rop;
      string rl = rop + lop;
      return lr > rl;  // 改变此处 > or < 即可找到最大数或最小数
    });
    string ans;
    for (auto &num : nums) {
      ans.append(to_string(num));
    }
    int i = 0;
    while (i < ans.length() && ans[i] == '0') {
      ++i;  // 找到所有前导 0
    }
    if (i == ans.length()) {
      return "0";
    }
    return ans.substr(i);
  }
};
