#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  long long findKthSmallest(vector<int> &coins, int k) {
    int n = coins.size();

    // 计算小等于 lim 的整数中，有几个整数能被集合里至少一种元素整除
    auto calc = [&](long long lim) {
      long long ret = 0;
      // 容斥原理，枚举所有子集
      for (int i = 1; i < (1 << n); i++) {
        int t = -1;
        long long l = 1;
        for (int j = 0; j < n; j++)
          if (i >> j & 1) {
            t = -t;
            // 计算最小公倍数
            l = l / gcd(l, coins[j]) * coins[j];
            // 防止最小公倍数溢出 long long
            if (l > lim) break;
          }
        ret += t * (lim / l);
      }
      return ret;
    };

    // 二分
    long long head = 1, tail = 1e12;
    while (head < tail) {
      long long mid = (head + tail) >> 1;
      if (calc(mid) >= k)
        tail = mid;
      else
        head = mid + 1;
    }
    return head;
  }
};
