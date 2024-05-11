#include <bits/stdc++.h>
using namespace std;

void dfs(int depth, int n, int m, int target_price, vector<int> &groups, vector<int> &ans, int current) {
  if (current > target_price) {
    return;
  }
  if (depth == n) {
    if (current == target_price) {
      if (ans.empty()) {
        ans = groups;
      } else if (groups < ans) {
        ans = groups;
      }
    }
    return;
  }
  for (int i = 0; i < m; ++i) {
    // 保证字典序最小
    if (i == 0 || (i > 0 && groups[i - 1] <= groups[i])) {
      int x = groups[i];
      groups[i]++;
      int next_sum = current - x * x + (x + 1) * (x + 1);
      dfs(depth + 1, n, m, target_price, groups, ans, next_sum);
      groups[i]--;
    }
  }
}

// 把 n 物品划分为 m 个组，不区分组之间的顺序，且要求价格之和为 target_price
// 求字典序最小的划分方案s
void solve(int n, int m, int target_price) {
  vector<int> groups(m, 1);  // 至少每组 1 个元素
  vector<int> ans;
  dfs(0, n - m, m, target_price, groups, ans, m);
  if (ans.empty()) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < m; ++i) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n, m, p;
  cin >> n >> m >> p;
  solve(n, m, p);
  return 0;
}
