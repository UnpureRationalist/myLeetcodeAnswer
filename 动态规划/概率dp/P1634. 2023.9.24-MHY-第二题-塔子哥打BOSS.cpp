#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 6010;

int n, t, h, x;
double f[N][M];  // 投掷前 i 次 点数总和为 j 的概率

int main() {
  int cnt = 0, num = 0;  // 硬币数量
  cin >> n >> h;

  for (int i = 0; i < n; i++) {
    cin >> t >> x;
    if (t == 1) {
      cnt += x;
    } else {
      h -= x;
      num += cnt;
      cnt = 0;
    }
  }

  f[0][0] = 1.0;
  for (int i = 1; i <= num; i++) {
    for (int j = i; j <= num * 6; j++) {
      for (int k = 1; k <= 6; k++) {
        if (j >= k) {
          f[i][j] += f[i - 1][j - k] * 1.0 / 6;
        }
      }
    }
  }

  double res = 0.0;
  if (h <= num * 6) {
    for (int i = h; i <= num * 6; i++) {
      res += f[num][i];
    }
  }
  cout << fixed << setprecision(4) << res << endl;
  return 0;
}
