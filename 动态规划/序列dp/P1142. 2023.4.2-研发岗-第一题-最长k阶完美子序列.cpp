#include <bits/stdc++.h>
using namespace std;

int solve(const string &str, int k) {
  int n = str.length();
  if (n == 0) {
    return 0;
  }
  vector<vector<int>> dp(n, vector<int>(26, 0));  // dp[i][j] 表示以前 i 个字母以字母 j 结尾的最长 k 阶完美子序列长度
  dp[0][str[0] - 'a'] = 1;
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    // 不选第 i 个字母
    for (int j = 0; j < 26; ++j) {
      dp[i][j] = dp[i - 1][j];
    }
    // 选第 i 个字母
    int low = str[i] - 'a' - k;
    int high = str[i] - 'a' + k;
    high = high >= 25 ? 25 : high;
    for (int j = max(0, low); j <= high; ++j) {
      dp[i][str[i] - 'a'] = max(dp[i][str[i] - 'a'], dp[i - 1][j] + 1);
    }
    ans = max(ans, dp[i][str[i] - 'a']);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  string str;
  int k;
  cin >> str >> k;
  cout << solve(str, k) << endl;
  return 0;
}
