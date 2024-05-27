#include <bits/stdc++.h>
using namespace std;

void dfs(int root, int father, const string &str, const vector<vector<int>> &adjList,
         vector<unordered_map<char, int>> &dp) {
  dp[root][str[root] == 'W' ? 'R' : 'W'] = 1;
  for (const auto &child : adjList[root]) {
    if (child == father) {
      continue;
    }
    dfs(child, root, str, adjList, dp);
    dp[root]['W'] += dp[child]['R'];
    dp[root]['R'] += dp[child]['W'];
  }
}

void solve(int n, const string &str, const vector<vector<int>> &adjList) {
  vector<char> visited(n, 0);
  vector<unordered_map<char, int>> dp(n);  // dp[i][c] 表示以 i 为根节点的子树染成 白色/红色 的最小操作次数
  for (auto &mp : dp) {
    mp['R'] = 0;
    mp['W'] = 0;
  }
  dfs(0, -1, str, adjList, dp);
  cout << min(dp[0]['W'], dp[0]['R']) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<vector<int>> adjList(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  solve(n, str, adjList);
  return 0;
}
