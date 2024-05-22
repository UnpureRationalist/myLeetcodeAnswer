#include <bits/stdc++.h>
using namespace std;

struct Gun {
  int hurt;
  int consume;
  int time;
};

int solve(int n, int m, int t, const vector<Gun> &guns) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  // 多重背包问题, dp[i][j]: 前 i 个大炮, 火药量为 j 的最大打击值
  for (int i = 1; i <= n; ++i) {
    const auto &[hurt, consume, time] = guns[i - 1];
    for (int j = 1; j <= m; ++j) {
      int mx = min(j / consume, t / time);  // 限定当前大炮的的最大个数
      for (int k = 0; k <= mx; ++k) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * consume] + k * hurt);
      }
    }
  }
  return dp[n][m];
}

int main() {
  ios::sync_with_stdio(false);
  int n, m, t;
  cin >> n >> m >> t;  // N 表示火药枪种类个数，M 表示火药数量， T 表示攻城时间
  vector<Gun> guns(n);
  for (int i = 0; i < n; ++i) {
    cin >> guns[i].hurt >> guns[i].consume >> guns[i].time;
  }
  cout << solve(n, m, t, guns) << endl;
  return 0;
}
