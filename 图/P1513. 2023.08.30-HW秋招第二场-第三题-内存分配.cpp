#include <bits/stdc++.h>
using namespace std;

void solve(int n, const vector<int> &nums, const vector<vector<int>> &adjList, vector<int> &indegree) {
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0) {
      q.emplace(i);
    }
  }
  int count = 0;
  int ans = 0;
  while (!q.empty()) {
    int size = q.size();
    count += size;
    int sum = 0;
    for (int i = 0; i < size; ++i) {
      int cur = q.front();
      q.pop();
      sum += nums[cur];
      for (const auto &target : adjList[cur]) {
        indegree[target]--;
        if (indegree[target] == 0) {
          q.emplace(target);
        }
      }
    }
    ans = max(ans, sum);
  }
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
  vector<int> indegree(n);
  for (int i = 0; i < n; ++i) {
    int x;
    for (int j = 0; j < n; ++j) {
      cin >> x;
      if (x == 1) {
        adjList[j].push_back(i);
        indegree[i]++;
      }
    }
  }
  solve(n, nums, adjList, indegree);
  return 0;
}
