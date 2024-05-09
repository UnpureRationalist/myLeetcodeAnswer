#include <bits/stdc++.h>
using namespace std;

void dfs(int depth, int n, vector<char> &visited, vector<int> &path, int &idx) {
  if (idx == 0) {
    return;
  }
  if (depth == n) {
    --idx;
    if (idx == 0) {
      for (int i = 0; i < n; ++i) {
        if (i > 0) {
          cout << " ";
        }
        cout << path[i] + 1;
      }
      cout << "\n";
    }
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      visited[i] = 1;
      path.push_back(i);
      dfs(depth + 1, n, visited, path, idx);
      path.pop_back();
      visited[i] = 0;
    }
  }
}

int factorial(int n) {
  int ans = 1;
  for (int i = 2; i <= n; ++i) {
    ans *= i;
  }
  return ans;
}

void solve(int n, int idx) {
  if (idx > factorial(n)) {
    cout << "-1" << endl;
    return;
  }
  vector<char> visited(n, 0);
  vector<int> path;
  dfs(0, n, visited, path, idx);
}

int main() {
  ios::sync_with_stdio(false);
  int n;

  int idx;
  cin >> n >> idx;
  solve(n, idx);
  return 0;
}
