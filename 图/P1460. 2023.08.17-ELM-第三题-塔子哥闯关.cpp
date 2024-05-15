#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int target;
  int weight;

  Edge() = default;

  Edge(int _id, int _w) : target(_id), weight(_w) {}

  bool operator<(const Edge &rop) const { return this->weight > rop.weight; }
};

void solve(int n, const vector<vector<Edge>> &adjList, const vector<int> &targets_lst) {
  unordered_set<int> targets(targets_lst.begin(), targets_lst.end());
  long long ans = 0;
  vector<long long> dis(n + 1, INT32_MAX);
  vector<char> visited(n + 1, 0);
  priority_queue<Edge> q;
  q.emplace(1, 0);
  dis[1] = 0;
  int count = 0;
  int target_size = targets.size();
  while (!q.empty()) {
    auto [cur, weight] = q.top();
    q.pop();
    if (visited[cur]) {
      continue;
    }
    visited[cur] = 1;
    if (targets.count(cur)) {
      ans += 2 * dis[cur];
      ++count;
    }
    if (count == target_size) {
      break;
    }
    for (const auto &[target, edge_weight] : adjList[cur]) {
      if (!visited[target] && dis[cur] + edge_weight < dis[target]) {
        dis[target] = dis[cur] + edge_weight;
        q.emplace(target, dis[target]);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<Edge>> adjList(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adjList[u].emplace_back(v, w);
    adjList[v].emplace_back(u, w);
  }
  vector<int> targets(q);
  for (int i = 0; i < q; ++i) {
    cin >> targets[i];
  }
  solve(n, adjList, targets);
  return 0;
}
