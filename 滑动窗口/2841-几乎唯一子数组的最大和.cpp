#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maxSum(vector<int> &nums, int m, int k) {
    int n = nums.size();
    unordered_map<int, int> num2times;
    long long sum = 0;
    long long ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      // 加入右指针指向的元素
      sum += nums[r];
      num2times[nums[r]]++;
      if (num2times.size() >= m) {
        ans = max(ans, sum);
      }
      // 若窗口长度等于 k， 移动左指针
      if (r - l + 1 == k) {
        sum -= nums[l];
        num2times[nums[l]]--;
        if (num2times[nums[l]] == 0) {
          num2times.erase(nums[l]);
        }
        ++l;
      }
    }
    return ans;
  }
};
