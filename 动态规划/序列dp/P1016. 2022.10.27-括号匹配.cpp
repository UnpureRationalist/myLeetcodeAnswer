#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long solve(const string &s) {
  int n = s.length();
  if (n % 2 != 0) {
    return 0;
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (s[i - 1] == '(' && j) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
      }

      if (s[i - 1] == ')') {
        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
      }

      if (s[i - 1] == '?') {
        if (j) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        }
        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
      }
    }
  }
  return dp[n][0];
}

int main() {
  ios::sync_with_stdio(false);
  string str;
  cin >> str;
  cout << solve(str) << endl;
  return 0;
}
