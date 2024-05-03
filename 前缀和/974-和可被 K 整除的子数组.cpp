#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int subarraysDivByK(vector<int> &nums, int k) {
    int n = nums.size();
    int res = 0;
    unordered_map<int, int> num2times;
    num2times[0] = 1;
    for (int i = 0, sum = 0; i < n; i++) {
      sum += nums[i];
      sum = (sum % k + k) % k;  // C++,Java取模结果可能为负数，把 sum 转换为取模结果
      if (num2times.count(sum)) {
        res += num2times[sum];
      }
      num2times[sum]++;
    }
    return res;
  }
};
