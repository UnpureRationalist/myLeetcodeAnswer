#include <bits/stdc++.h>
using namespace std;

void solve(int n, const vector<set<int>> &adjList, const unordered_set<int> &busy_nodes) {
  vector<int> pre(n, -1);
  vector<char> visited(n, 0);
  queue<int> q;
  if (busy_nodes.find(0) == busy_nodes.end()) {
    q.emplace(0);
    visited[0] = 1;
  }
  int leaf = -1;
  int step = 0;
  while (!q.empty()) {
    int size = q.size();
    bool over = false;
    for (int i = 0; i < size; ++i) {
      int cur = q.front();
      q.pop();
      bool is_leaf = false;
      for (const auto &next : adjList[cur]) {
        if (busy_nodes.find(next) == busy_nodes.end() && !visited[next]) {
          pre[next] = cur;
          visited[next] = 1;
          q.emplace(next);

          if (adjList[next].size() == 1) {
            is_leaf = true;
            leaf = next;
            break;
          }
        }
      }
      if (is_leaf) {
        over = true;
        break;
      }
    }
    if (over) {
      break;
    }
    step++;
  }
  if (leaf == -1) {
    cout << "NULL" << endl;
    return;
  }
  vector<int> path;
  path.push_back(leaf);
  while (pre[leaf] != -1) {
    leaf = pre[leaf];
    path.push_back(leaf);
  }
  reverse(path.begin(), path.end());
  int len = path.size();
  for (int i = 0; i < len; ++i) {
    if (i > 0) {
      cout << "->";
    }
    cout << path[i];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<set<int>> adjList(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adjList[x].insert(y);
    adjList[y].insert(x);
  }
  int d;
  cin >> d;
  unordered_set<int> busy_nodes;
  for (int i = 0; i < d; ++i) {
    int x;
    cin >> x;
    busy_nodes.insert(x);
  }
  solve(n, adjList, busy_nodes);
  return 0;
}
