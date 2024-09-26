#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      int square = sqrt(i);
      if (square * square == i) {
        dp[i] = 1;
      } else {
        for (int j = 1; j <= square; ++j) {
          dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
      }
    }
    return dp[n];
  }
};
