#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

#define x first
#define y second

typedef long long ll;

const int N = 1E5 + 10;

vector<PII> g[N];
int n, f[N];

void dfs(int u, int fa) {
  for (auto &[x, w] : g[u]) {
    if (x == fa) {
      continue;
    }
    dfs(x, u);
    if (f[x]) {
      f[u] += f[x];
    } else if (w) {
      f[u]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  dfs(1, 0);
  cout << f[1] << endl;
  return 0;
}
