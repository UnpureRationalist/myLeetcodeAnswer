#include <bits/stdc++.h>
using namespace std;

unordered_set<int> getLeafs(int n, const vector<unordered_set<int>> &adjList) {
  unordered_set<int> leafs;
  for (int i = 1; i <= n; ++i) {
    if (adjList[i].size() == 1) {
      leafs.insert(i);
    }
  }
  leafs.erase(1);  // 1 是根节点，即使其度为 1 也不算叶子节点
  return leafs;
}

void bfs(int root, int k, const vector<unordered_set<int>> &adjList, unordered_map<int, int> &leaf2depth,
         long long &total, const unordered_set<int> &leafs, vector<char> &visited) {
  int depth = 0;
  visited[root] = 1;
  queue<int> q;
  q.emplace(root);

  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      int cur = q.front();
      q.pop();
      if (depth <= k) {
        ++total;
      }
      if (leafs.find(cur) != leafs.end()) {
        leaf2depth[cur] = depth;
      }
      for (const auto &next : adjList[cur]) {
        if (!visited[next]) {
          visited[next] = 1;
          q.emplace(next);
        }
      }
    }
    ++depth;
  }
}

void solve(int n, int k, const vector<unordered_set<int>> &adjList) {
  auto leafs = getLeafs(n, adjList);
  unordered_map<int, int> leaf2depth;  // 计算根节点到每个叶子节点的距离
  long long total = 0;
  vector<char> visited(n + 1, 0);
  bfs(1, k, adjList, leaf2depth, total, leafs, visited);
  long long ans = total;
  for (auto &[node, depth] : leaf2depth) {
    if (depth < k) {
      ans += (k - depth);
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<unordered_set<int>> adjList(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adjList[u].insert(v);
    adjList[v].insert(u);
  }
  solve(n, k, adjList);
  return 0;
}
