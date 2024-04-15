#include "header.h"

class Solution {
 public:
  int trailingZeroes(int n) {
    if (n < 5) {
      return 0;
    }
    int ans = 0;
    for (int i = 5; i <= n; i += 5) {
      int value = i;
      while ((value % 5) == 0) {
        value /= 5;
        ans += 1;
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int trailingZeroes(int n) {
    int ans = 0;
    while (n) {
      n /= 5;
      ans += n;
    }
    return ans;
  }
};
