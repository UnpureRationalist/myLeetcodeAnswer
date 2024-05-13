#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 40;

ll cache[MAXN][MAXN] = {-1};  // cache[i][j] 表示节点数为 i，高度不超过 j 的二叉查找树的数量

void init() {
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      cache[i][j] = -1;
    }
  }
}

long long dfs(int n, int k) {
  if (cache[n][k] != -1) {
    return cache[n][k];
  }
  if (n == 0) {
    return 1;
  }
  if (k == 0) {
    return 0;
  }
  if (n == 1 && k == 1) {
    cache[n][k] = 1;
    return cache[n][k];
  }
  long long ans = 0;
  for (int root = 1; root <= n; ++root) {
    ans += dfs(root - 1, k - 1) * dfs(n - root, k - 1);
  }
  cache[n][k] = ans;
  return cache[n][k];
}

void solve(int n, int k) {
  init();
  // 枚举根节点
  long long ans = 0;
  for (int root = 1; root <= n; ++root) {
    // 左 * 右
    ans += dfs(root - 1, k - 1) * dfs(n - root, k - 1);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  solve(n, k);
  return 0;
}
