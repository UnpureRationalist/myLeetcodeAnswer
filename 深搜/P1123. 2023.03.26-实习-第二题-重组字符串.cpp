#include <bits/stdc++.h>
using namespace std;

void dfs(int depth, int n, const vector<string> &strs, string &path, unordered_set<char> &selected, int &ans) {
  if (depth == n) {
    ++ans;
    return;
  }
  int str_len = strs[depth].length();
  for (int i = 0; i < str_len; ++i) {
    char c = strs[depth][i];
    if (!selected.count(c)) {
      selected.insert(c);
      path.push_back(c);
      dfs(depth + 1, n, strs, path, selected, ans);
      path.pop_back();
      selected.erase(c);
    }
  }
}

void solve(int n, const vector<string> &strs) {
  int ans = 0;
  string path;
  unordered_set<char> selected;
  dfs(0, n, strs, path, selected, ans);
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; ++i) {
    cin >> strs[i];
    sort(strs[i].begin(), strs[i].end());
    strs[i].erase(unique(strs[i].begin(), strs[i].end()), strs[i].end());
  }
  solve(n, strs);
  return 0;
}
