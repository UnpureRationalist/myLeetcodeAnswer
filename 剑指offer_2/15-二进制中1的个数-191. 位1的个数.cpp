#include "header.h"

// 仅能处理非负数，负数会导致死循环的解法
class Solution {
 public:
  int hammingWeight(int n) {
    int ans = 0;
    while (n) {
      ans += n & 1;
      n >>= 1;
    }
    return ans;
  }
};

// 避免负数死循环解法
class Solution {
 public:
  int hammingWeight(int n) {
    int ans = 0;
    unsigned int flag = 1;
    while (flag) {
      ans += n & flag ? 1 : 0;  // 每次判断 flag 为 1 的位 n 是否也为 1
      flag <<= 1;
    }
    return ans;
  }
};

// 循环次数更少的解法
class Solution {
 public:
  int hammingWeight(int n) {
    int ans = 0;
    while (n) {
      ans++;
      n = n & (n - 1);
    }
    return ans;
  }
};

// 进阶版：Leetcode 338. 比特位计数 利用上面 n&(n-1) 规律进行动态规划
class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    if (n == 0) {
      return dp;
    }
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i & (i - 1)] + 1;
    }
    return dp;
  }
};
