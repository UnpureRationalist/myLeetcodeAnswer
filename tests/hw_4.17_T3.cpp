#include <bits/stdc++.h>
using namespace std;

struct Vert {
  int index;
  int weight;

  Vert() {}

  Vert(int i, int w) : index(i), weight(w) {}

  bool operator<(const Vert &rhs) const {
    if (this->weight != rhs.weight) {
      return this->weight > rhs.weight;
    }
    return this->index > rhs.index;
  }
};

void solve(const vector<vector<int>> &adjMatrix, const vector<int> &remainCapacity, int fault_node, int move_weight) {
  int n = adjMatrix.size();
  int already_moved = 0;

  vector<int> dis(n, INT_MAX);
  vector<char> visited(n, 0);
  dis[fault_node] = 0;

  priority_queue<Vert> q;
  q.emplace(fault_node, 0);

  vector<int> ans;

  while (!q.empty()) {
    auto [cur_idx, weight] = q.top();
    q.pop();
    if (visited[cur_idx]) {
      continue;
    }
    visited[cur_idx] = 1;
    if (cur_idx != fault_node) {
      ans.push_back(cur_idx);
      already_moved += remainCapacity[cur_idx];
    }
    if (already_moved >= move_weight) {
      break;
    }
    for (int index = 0; index < n; ++index) {
      int weight = adjMatrix[cur_idx][index];
      if (weight != -1) {
        if (!visited[index] && dis[cur_idx] + weight < dis[index]) {
          dis[index] = dis[cur_idx] + weight;
          q.emplace(index, dis[index]);
        }
      }
    }
  }
  cout << ans[0];
  for (int i = 1; i < ans.size(); ++i) {
    cout << " " << ans[i];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> adjMatrix[i][j];
    }
  }
  vector<int> remainCapacity(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> remainCapacity[i];
  }
  int fault_node;
  cin >> fault_node;
  int move_weight;
  cin >> move_weight;

  solve(adjMatrix, remainCapacity, fault_node, move_weight);

  return 0;
}