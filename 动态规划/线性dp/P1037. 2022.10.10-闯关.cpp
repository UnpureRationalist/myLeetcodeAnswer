#include <bits/stdc++.h>
using namespace std;

// 最长公共子串问题
void solve(const string &str1, const string &str2) {
  int m = str1.length();
  int n = str2.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > ans) {
          ans = dp[i][j];
        }
      }
    }
  }
  cout << ans * 2 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  string str1, str2;
  cin >> str1 >> str2;

  solve(str1, str2);
  return 0;
}
