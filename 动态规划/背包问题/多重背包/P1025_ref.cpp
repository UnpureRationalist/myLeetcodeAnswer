#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int a[N], b[N], c[N], f[N][N];

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }

  // 多重背包问题, f[i][j]: 前i个大炮, 火药量为j的最大打击值
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int mx = min(j / b[i], t / c[i]);  // 限定当前大炮的的最大个数
      for (int k = 0; k <= mx; ++k) {
        f[i][j] = max(f[i][j], f[i - 1][j - k * b[i]] + k * a[i]);
      }
    }
  }
  cout << f[n][m] << endl;
  return 0;
}
