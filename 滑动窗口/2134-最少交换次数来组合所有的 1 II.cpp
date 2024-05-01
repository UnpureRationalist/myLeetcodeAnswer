#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSwaps(vector<int> &nums) {
    int n = nums.size();
    int ans = INT32_MAX;
    int k = count(nums.begin(), nums.end(), 1);
    if (k == n) {
      return 0;
    }
    int count = 0;
    for (int l = 0, r = 0; l < n; ++l) {
      while ((r % n) != ((l + k) % n)) {
        if (nums[r % n] == 1) {
          ++count;
        }
        ++r;
      }
      ans = min(ans, k - count);
      // 更新 count，左指针在 for 循环中移动
      if (nums[l] == 1) {
        --count;
      }
    }
    return ans;
  }
};

// 通过拷贝数组到末尾，处理环
class Solution {
 public:
  int minSwaps(vector<int> &nums) {
    // 环形数组 把原数组复制一份拷贝到数组末尾，即可破环成链
    int n = nums.size(), cnt = 0;
    vector<int> v;
    for (int i = 0; i < n * 2; i++) {
      if (i < n) {
        if (nums[i]) {
          cnt++;  // 统计1的个数
        }
      }
      v.push_back(nums[i % n]);
    }
    int res = n;
    for (int l = 0, r = 0, num = 0; r < 2 * n; r++) {
      num += v[r];
      while (r - l + 1 > cnt) {
        num -= v[l++];
      }
      res = min(res, cnt - num);
    }
    return res;
  }
};

// 转化为统计区间 0 的个数
class Solution {
 public:
  int minSwaps(vector<int> &nums) {
    int n = nums.size();
    int cnt = accumulate(nums.begin(), nums.end(), 0);
    if (cnt == 0) {
      return 0;
    }

    int cur = 0;
    for (int i = 0; i < cnt; ++i) {
      cur += (1 - nums[i]);
    }
    int ans = cur;
    for (int i = 1; i < n; ++i) {
      if (nums[i - 1] == 0) {
        --cur;
      }
      if (nums[(i + cnt - 1) % n] == 0) {
        ++cur;
      }
      ans = min(ans, cur);
    }
    return ans;
  }
};
