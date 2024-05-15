#include <bits/stdc++.h>
using namespace std;

void solve(int n, const vector<vector<int>> &adjList, vector<int> &indegree) {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (indegree[i] == 0) {
      q.emplace(i);
    }
  }
  int count = 0;
  int step = 0;
  while (!q.empty()) {
    int size = q.size();
    ++step;
    count += size;
    for (int i = 0; i < size; ++i) {
      int cur = q.front();
      q.pop();
      for (const auto &target : adjList[cur]) {
        indegree[target]--;
        if (indegree[target] == 0) {
          q.emplace(target);
        }
      }
    }
  }
  int ans = count == n ? step : -1;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> adjList(n + 1);
  vector<int> indegree(n + 1);
  for (int i = 1; i <= n; ++i) {
    int m;
    cin >> m;
    indegree[i] += m;
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      adjList[x].push_back(i);
    }
  }
  solve(n, adjList, indegree);
  return 0;
}
