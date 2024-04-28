#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    const int MOD = 1'000'000'007;
    vector<vector<array<long long, 2>>> f(zero + 1, vector<array<long long, 2>>(one + 1));
    for (int i = 1; i <= min(limit, zero); i++) {
      f[i][0][0] = 1;
    }
    for (int j = 1; j <= min(limit, one); j++) {
      f[0][j][1] = 1;
    }
    for (int i = 1; i <= zero; i++) {
      for (int j = 1; j <= one; j++) {
        // + MOD 保证答案非负
        f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] + (i > limit ? MOD - f[i - limit - 1][j][1] : 0)) % MOD;
        f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] + (j > limit ? MOD - f[i][j - limit - 1][0] : 0)) % MOD;
      }
    }
    return (f[zero][one][0] + f[zero][one][1]) % MOD;
  }
};
