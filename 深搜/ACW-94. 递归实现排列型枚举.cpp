#include <bits/stdc++.h>
using namespace std;

void dfs(int depth, int n, vector<char> &visited, vector<int> &path) {
  if (depth == n) {
    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        cout << " ";
      }
      cout << path[i] + 1;
    }
    cout << "\n";
  }
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      visited[i] = 1;
      path.push_back(i);
      dfs(depth + 1, n, visited, path);
      path.pop_back();
      visited[i] = 0;
    }
  }
}

void solve(int n) {
  vector<char> visited(n, 0);
  vector<int> path;
  dfs(0, n, visited, path);
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  solve(n);
  return 0;
}
