#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumDifference(vector<int> &nums, int k) {
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      ans = min(ans, abs(x - k));
      for (int j = i - 1; j >= 0 && (nums[j] & x) != nums[j]; j--) {
        nums[j] &= x;
        ans = min(ans, abs(nums[j] - k));
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int minimumDifference(vector<int> &nums, int K) {
    int n = nums.size();
    const int MAXP = 30;

    // last[i][p]：在位置 i 的左边（含位置 i），二进制第 p 位是 0 的最近位置在哪
    int last[n][MAXP];
    for (int p = 0; p < MAXP; p++) {
      if (nums[0] >> p & 1)
        last[0][p] = -1;
      else
        last[0][p] = 0;
    }
    for (int i = 1; i < n; i++)
      for (int p = 0; p < MAXP; p++) {
        if (nums[i] >> p & 1)
          last[i][p] = last[i - 1][p];
        else
          last[i][p] = i;
      }

    int ans = 1e9;
    // 枚举子数组右端点
    for (int i = 0; i < n; i++) {
      // 对于二进制的每一位，拿出上一个 0 在什么位置
      vector<int> pos;
      for (int p = 0; p < MAXP; p++)
        if (last[i][p] >= 0) pos.push_back(last[i][p]);
      sort(pos.begin(), pos.end(), greater<int>());
      // 枚举 logX 种 AND 值
      int now = nums[i];
      ans = min(ans, abs(K - now));
      for (int j : pos) {
        now &= nums[j];
        ans = min(ans, abs(K - now));
      }
    }
    return ans;
  }
};
