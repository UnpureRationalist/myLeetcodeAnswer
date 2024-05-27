#include <bits/stdc++.h>
using namespace std;

void dfs(int root, int father, int &ans, const vector<int> &nums, const vector<vector<int>> &adjList, vector<int> &dp) {
  dp[root] = nums[root];
  for (const auto &child : adjList[root]) {
    if (child == father) {
      continue;
    }
    dfs(child, root, ans, nums, adjList, dp);
    dp[root] += max(0, dp[child]);
  }
  ans = max(ans, dp[root]);
}

void solve(int n, const vector<int> &nums, const vector<vector<int>> &adjList) {
  int ans = INT32_MIN;
  vector<int> dp(n);
  dfs(0, -1, ans, nums, adjList, dp);
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  vector<vector<int>> adjList(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  solve(n, nums, adjList);
  return 0;
}
