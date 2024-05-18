#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1E3 + 10;

int f[N][N], n, m;

int main() {
  cin >> n >> m;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < n; k++) {
      for (int j = i; j <= m; j += i) {
        int cur = (j + k) % n;
        f[i][cur] = (f[i][cur] + f[i - 1][k]) % mod;
      }
    }
  }
  cout << f[n][0] << endl;
  return 0;
}
