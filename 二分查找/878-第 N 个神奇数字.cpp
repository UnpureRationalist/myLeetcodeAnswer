#include <bits/stdc++.h>
using namespace std;

class Solution {
  const int MOD = 1e9 + 7;
  long long lcm_res = 1;

  // 容斥原理
  bool check(int n, long long a, long long b, long long x) { return (x / a + x / b - x / lcm_res) >= n; }

 public:
  int nthMagicalNumber(int n, int a, int b) {
    long long gcd_res = gcd(a, b);
    lcm_res = static_cast<long long>(a) * b / gcd_res;
    long long left = 2;
    long long right = INT64_MAX;
    long long ans = 1;
    while (left <= right) {
      long long mid = left + (right - left) / 2;
      bool ok = check(n, a, b, mid);
      if (ok && !check(n, a, b, mid - 1)) {
        ans = mid;
        break;
      }
      if (ok) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans % MOD;
  }
};
