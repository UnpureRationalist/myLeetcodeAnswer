#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int n, w[N], k, f[N][N];

int main() {
  cin >> n >> k;
  double p[5] = {0.8, 1.0, 1.1, 1.2, 1.3};
  for (int i = 1; i <= n; i++) cin >> w[i];
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      // 第i个人用0~4个机器人帮助他
      for (int v = j; v >= 0 && v >= j - 4; v--) {
        f[i][j] = max(f[i][j], f[i - 1][v] + (int)(w[i] * p[j - v]));
      }
      res = max(res, f[i][j]);
    }
  }
  cout << res << endl;
  return 0;
}
