#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int n = nums.size();
    // 考虑以下标 i 结尾的方案数
    unordered_map<int, int> num2times;
    num2times[0] = 1;  // 前缀和为 0 出现一次，相当于下标 -1 位置
    int sum = 0;
    int ans = 0;
    for (const auto &num : nums) {
      sum += num;                    // 更新前缀和
      ans += num2times[sum - goal];  // presum[i] - presum[j] = goal，则 presum[j] = presum[i] - goal = sum - goal
      num2times[sum]++;
    }
    return ans;
  }
};
