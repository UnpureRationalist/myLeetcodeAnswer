#include <bits/stdc++.h>
using namespace std;

void dfs(int target, int cur_value, int &max_value, unordered_set<int> &selected) {
  if (target == 0) {
    if (cur_value > max_value) {
      max_value = cur_value;
    }
    return;
  }
  // 枚举从 1 到 min(target, 9) 的数位
  int upper = min(9, target);
  for (int i = 1; i <= upper; ++i) {
    if (selected.find(i) == selected.end()) {
      selected.insert(i);
      dfs(target - i, cur_value * 10 + i, max_value, selected);
      selected.erase(i);
    }
  }
}

void solve(int x) {
  int ans = -1;
  int cur = 0;
  unordered_set<int> selected;
  dfs(x, cur, ans, selected);
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int x;
  cin >> x;
  solve(x);
  return 0;
}
