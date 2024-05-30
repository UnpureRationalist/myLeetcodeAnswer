#include <bits/stdc++.h>
using namespace std;

void solve(int n, const vector<int> &lops, int m, const vector<int> &rops) {
  int lsum = accumulate(lops.begin(), lops.end(), 0);
  int rsum = accumulate(rops.begin(), rops.end(), 0);
  vector<vector<double>> ldp(n + 1, vector<double>(max(lsum, rsum) + 1, 0.0));  // dp[i][j] 表示前 i 个骰子和为 j 的概率
  vector<vector<double>> rdp(m + 1, vector<double>(max(lsum, rsum) + 1, 0.0));

  // init
  ldp[0][0] = 1.0;
  rdp[0][0] = 1.0;

  // calculate ldp
  for (int i = 1; i <= n; ++i) {
    int num = lops[i - 1];
    for (int j = 1; j <= lsum; ++j) {
      for (int k = 1; k <= num && j >= k; ++k) {
        ldp[i][j] += ldp[i - 1][j - k] / num;
      }
    }
  }

  // calculate rdp
  for (int i = 1; i <= m; ++i) {
    int num = rops[i - 1];
    for (int j = 1; j <= rsum; ++j) {
      for (int k = 1; k <= num && j >= k; ++k) {
        rdp[i][j] += rdp[i - 1][j - k] / num;
      }
    }
  }

  // calculate probability that lop[n][.] > rop[m][.]
  double res = 0.0, pre = 0.0;
  for (int i = 2; i <= lsum; ++i) {
    pre += rdp[m][i - 1];
    res += pre * ldp[n][i];
  }
  cout << fixed << setprecision(3) << res << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> lops(n), rops(m);
  for (int i = 0; i < n; ++i) {
    cin >> lops[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> rops[i];
  }
  solve(n, lops, m, rops);
  return 0;
}
