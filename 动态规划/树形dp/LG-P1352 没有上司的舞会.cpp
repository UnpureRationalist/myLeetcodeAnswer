#include <bits/stdc++.h>
using namespace std;

int findRoot(int n, const vector<vector<int>> &adjList) {
  vector<char> childs(n, 0);
  for (const auto &lst : adjList) {
    for (const auto &child : lst) {
      childs[child] = 1;
    }
  }
  return find(childs.begin(), childs.end(), 0) - childs.begin();
}

void dfs(int root, const vector<int> &nums, const vector<vector<int>> &adjList, vector<vector<int>> &dp) {
  // 选
  dp[root][1] = nums[root];

  for (const auto &child : adjList[root]) {
    dfs(child, nums, adjList, dp);
    dp[root][0] += max(dp[child][1], dp[child][0]);  // 不选 root
    dp[root][1] += dp[child][0];                     // 选 root
  }
}

void solve(int n, const vector<int> &nums, const vector<vector<int>> &adjList) {
  int root = findRoot(n, adjList);
  vector<vector<int>> dp(n, vector<int>(2, 0));  // dp[i][1/0] 表示以 i 为根节点，选或者不选的最大快乐指数
  dfs(root, nums, adjList, dp);
  cout << max(dp[root][0], dp[root][1]) << endl;
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
    int child, father;
    cin >> child >> father;
    adjList[father - 1].push_back(child - 1);
  }
  solve(n, nums, adjList);
  return 0;
}
