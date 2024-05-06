#include <bits/stdc++.h>
using namespace std;

constexpr int HASH_LEN = 110;
class Solution {
  vector<int> num2times;

  // 如果子数组中第 x 小整数 是 负数 ，那么美丽值为第 x 小的数，否则美丽值为 0 。
  int getBeauty(int x) {
    int i = 0;
    while (num2times[i] == 0) {
      ++i;
    }
    while (x >= 1 && i < 50) {
      if (num2times[i] >= x) {
        return i - 50;
      }
      x -= num2times[i];
      ++i;
    }
    return 0;
  }

 public:
  vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
    num2times.resize(HASH_LEN, 0);
    int n = nums.size();
    vector<int> result(n - k + 1, 0);
    int idx = 0;
    for (int l = 0, r = 0; l <= n - k; ++l) {
      while (r < n && r - l < k) {
        num2times[nums[r] + 50]++;
        ++r;
      }
      result[idx++] = getBeauty(x);
      num2times[nums[l] + 50]--;
    }
    return result;
  }
};
