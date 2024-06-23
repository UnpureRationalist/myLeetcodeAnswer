#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool isZero(double x) { return abs(x) < 1e-6; }

  double innerPow(double x, unsigned int n) {
    if (n == 0) {
      return 1.0;
    }
    if (n & 1) {
      return x * innerPow(x, n - 1);
    }
    double temp = innerPow(x, n / 2);
    return temp * temp;
  }

 public:
  double myPow(double x, int n) {
    if (isZero(x)) {
      return 0.0;
    }
    if (x == 1.0 || n == 0) {
      return 1.0;
    }
    if (n < 0) {
      unsigned int exp = static_cast<unsigned int>(n);
      return 1.0 / innerPow(x, -exp);
    }
    // n > 0
    return innerPow(x, n);
  }
};