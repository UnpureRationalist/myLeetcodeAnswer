#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 55;

ll n, w[N], f[N][N], k;

unordered_map<int, int> cnts;

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (!j)
        f[i][j] = 1;
      else
        f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  init();
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnts[x]++;
  }
  ll res = 1;
  for (auto &[u, v] : cnts) {
    if (v < k) {
      continue;
    }
    ll s = 0;
    for (int i = 0; i <= v; i += k) {
      s += f[v][i];
    }
    res *= s;
  }
  res--;  // 去掉空集
  cout << res << endl;
  return 0;
}
