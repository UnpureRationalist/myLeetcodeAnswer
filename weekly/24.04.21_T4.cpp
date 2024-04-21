#include <bits/stdc++.h>
using namespace std;

class Solution {
  struct Edge {
    int target;
    int weight;
    int id;

    Edge() = default;

    Edge(int t, int w, int i) : target(t), weight(w), id(i) {}

    void setValue(int t, int w, int i) {
      target = t;
      weight = w;
      id = i;
    }

    bool operator<(const Edge &rop) const { return weight > rop.weight; }
  };

  vector<vector<Edge>> adjList;

  void edges2adjList(int n, vector<vector<int>> &edges) {
    int num_edges = edges.size();
    adjList.resize(n);
    for (int i = 0; i < num_edges; ++i) {
      int idx1 = edges[i][0];
      int idx2 = edges[i][1];
      int weight = edges[i][2];
      adjList[idx1].emplace_back(idx2, weight, i);
      adjList[idx2].emplace_back(idx1, weight, i);
    }
  }

  vector<long long> distance;

  void dijkstra(int n) {
    int start = 0;
    int target = n - 1;
    distance.resize(n, INT_MAX);
    vector<char> visited(n, false);
    priority_queue<Edge> q;
    q.emplace(start, 0, 0);
    distance[start] = 0;
    while (!q.empty()) {
      auto [cur, weight, idx] = q.top();
      q.pop();
      if (visited[cur]) {
        continue;
      }
      visited[cur] = 1;
      for (auto &[target, edge_weight, edge_id] : adjList[cur]) {
        if (!visited[target] && distance[cur] + edge_weight < distance[target]) {
          distance[target] = distance[cur] + edge_weight;
          q.emplace(target, distance[target], edge_id);
        }
      }
    }
  }

  void addEdges(vector<bool> &result, int start, int end, int weight) {
    if (start == 0) {
      return;
    }
    for (auto [target, edge_weight, edge_id] : adjList[start]) {
      if (distance[target] + edge_weight == weight) {
        result[edge_id] = true;
        addEdges(result, target, end, distance[target]);
      }
    }
  }

 public:
  vector<bool> findAnswer(int n, vector<vector<int>> &edges) {
    edges2adjList(n, edges);
    dijkstra(n);
    // distance[i] 表示从 0 到 i 的最短路径
    int num_edges = edges.size();
    vector<bool> result(num_edges, false);
    if (distance[n - 1] < INT_MAX) {
      addEdges(result, n - 1, 0, distance[n - 1]);
    }
    return result;
  }
};
