#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
#define x first
#define y second

typedef long long ll;

const int N = 2E5 + 10, mod = 1e9 + 7;
int n, m;

ll f[N], w[N], d[N], sum[N];

vector<int> g[N];

vector<ll> dfs(int u, int fa, int depth) {
  d[u] = depth;
  sum[u] = w[u];
  f[u] += 1ll * w[u] * d[u];
  for (int &x : g[u]) {
    if (x == fa) {
      continue;
    }
    auto t = dfs(x, u, depth + 1);
    f[u] += t[0];
    sum[u] += t[1];
  }
  return {f[u], sum[u]};
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 0, 1);
  ll res = f[1];
  for (int i = 2; i <= n; i++) {  // 考虑替换第i个节点
    if (d[i] <= 2) {
      continue;
    }
    ll down = 1ll * (d[i] - 2) * sum[i];
    res = min(res, f[1] - down);
  }
  cout << res << endl;
  return 0;
}
