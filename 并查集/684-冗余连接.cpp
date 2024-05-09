#include <bits/stdc++.h>
using namespace std;

class Solution {
  int Find(vector<int> &parent, int index) {
    if (parent[index] != index) {
      parent[index] = Find(parent, parent[index]);
    }
    return parent[index];
  }

  void Union(vector<int> &parent, int index1, int index2) { parent[Find(parent, index1)] = Find(parent, index2); }

 public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
    for (auto &edge : edges) {
      int node1 = edge[0], node2 = edge[1];
      if (Find(parent, node1) != Find(parent, node2)) {
        Union(parent, node1, node2);
      } else {
        return edge;  // 两个节点已经联通，返回冗余边
      }
    }
    return vector<int>{};
  }
};
