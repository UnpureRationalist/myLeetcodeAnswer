#include <bits/stdc++.h>
using namespace std;

void dfs(int root, int father, const vector<vector<int>> &adjList, vector<int> &dp) {
  for (const auto &child : adjList[root]) {
    if (child == father) {
      continue;
    }
    dfs(child, root, adjList, dp);
    dp[root] += dp[child];
  }
  if (dp[root] % 2 == 0) {
    dp[root] += 1;
  }
}

void fillColor(int root, int father, const vector<vector<int>> &adjList, const vector<int> &dp, string &str) {
  int sum = 0;
  for (const auto &child : adjList[root]) {
    if (child == father) {
      continue;
    }
    sum += dp[child];
    fillColor(child, root, adjList, dp, str);
  }
  if (sum % 2 == 0) {
    str[root] = 'B';
  }
}

void solve(int n, const vector<vector<int>> &adjList) {
  vector<int> dp(n, 0);  // dp[i] 表示以 i 为根节点的树中蓝色节点最大数
  dfs(0, -1, adjList, dp);
  string str(n, 'R');
  fillColor(0, -1, adjList, dp, str);
  cout << str << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> adjList(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  solve(n, adjList);
  return 0;
}
