#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long minEnd(int n, int x) {
    n--;  // 先把 n 减一，这样下面讨论的 n 就是原来的 n-1
    long long ans = x;
    int i = 0, j = 0;
    while (n >> j) {
      // x 的第 i 个比特值是 0，即「空位」
      if (((ans >> i) & 1) == 0) {
        // 空位填入 n 的第 j 个比特值
        ans |= (long long)(n >> j & 1) << i;
        j++;
      }
      i++;
    }
    return ans;
  }
};
