#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int n, m, q;
  cin >> n >> m >> q;
  unordered_map<int, int> fa;
  set<pair<int, int>> fr;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    fr.insert({u, v});  // 记录朋友关系
  }

  vector<tuple<int, int, int>> qs;  // 查询

  for (int i = 0; i < q; i++) {
    int op, u, v;
    cin >> op >> u >> v;
    if (op == 1) {
      fr.erase({u, v});  // 删除朋友关系
    }
    qs.push_back({op, u, v});
  }

  reverse(qs.begin(), qs.end());
  vector<char> ans;

  function<int(int)> find = [&](int x) { return fa.count(x) ? fa[x] = find(fa[x]) : x; };

  auto merge = [&](int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      fa[x] = y;
    }
  };

  for (auto &[u, v] : fr) {
    merge(u, v);  // 根据删除后的好友关系，建立并查集
  }
  for (auto [op, u, v] : qs) {
    if (op == 1) {
      merge(u, v);  // 恢复好友关系
    } else {
      ans.push_back(find(u) == find(v));
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto &s : ans) {
    cout << (s ? "Yes" : "No") << '\n';
  }
  return 0;
}
