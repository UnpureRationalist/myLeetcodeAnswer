#include <bits/stdc++.h>
using namespace std;

void print(const vector<int> &path) {
  int n = path.size();
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << path[i];
  }
  cout << "\n";
}

void dfs(int depth, int n, vector<int> &path) {
  if (depth == n) {
    print(path);
    return;
  }
  // 选
  path.push_back(depth + 1);
  dfs(depth + 1, n, path);
  path.pop_back();
  // 不选
  dfs(depth + 1, n, path);
}

void solve(int n) {
  vector<int> path;
  dfs(0, n, path);
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  solve(n);
  return 0;
}
