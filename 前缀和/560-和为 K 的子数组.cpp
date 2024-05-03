#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    int sum = 0;
    int ans = 0;
    unordered_map<int, int> num2times;
    num2times[0] = 1;
    for (const auto &num : nums) {
      sum += num;
      ans += num2times[sum - k];
      num2times[sum]++;
    }
    return ans;
  }
};
