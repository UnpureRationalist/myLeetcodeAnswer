#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    // dp[i][j][k]， k 表示选与不选
    vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
    constexpr int MOD = 1000000007;

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;  // 初始化

    // 递推
    for (int i = 0; i <= zero; i++) {
      for (int j = 0; j <= one; j++) {
        for (int k = 0; k < 2; k++) {
          if (k == 0) {  // 选 0
            for (int l = 1; l <= limit; l++) {
              if (i - l >= 0) {
                dp[i][j][k] += dp[i - l][j][1];  // dp[i - l][j] 位置必须选 1
                dp[i][j][k] %= MOD;
              }
            }
          } else {  // 选 1
            for (int l = 1; l <= limit; l++) {
              if (j - l >= 0) {
                dp[i][j][k] += dp[i][j - l][0];  // dp[i][j - l] 位置必须选 0
                dp[i][j][k] %= MOD;
              }
            }
          }
        }
      }
    }
    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
  }
};
