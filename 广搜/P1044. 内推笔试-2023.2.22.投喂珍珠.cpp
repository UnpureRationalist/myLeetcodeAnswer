#include <bits/stdc++.h>
using namespace std;

struct Node {
  int id;
  int food;
  int depth;

  Node(int _id, int _food, int _depth) : id(_id), food(_food), depth(_depth) {}
};

void solve(int n, int m, const vector<int> &horses, const vector<unordered_set<int>> &adjList) {
  vector<char> visited(n + 1, 0);
  queue<Node> q;
  if (horses[1] <= m) {
    q.emplace(1, horses[1], 1);
    visited[1] = 1;
  }
  int max_depth = 0;
  int min_food = 0;
  while (!q.empty()) {
    auto [cur, food, depth] = q.front();
    q.pop();
    if (depth > max_depth) {
      max_depth = depth;
      min_food = food;
    } else if (depth == max_depth) {
      if (food < min_food) {
        min_food = food;
      }
    }
    for (const auto &next : adjList[cur]) {
      if (!visited[next] && food + horses[next] <= m) {
        q.emplace(next, food + horses[next], depth + 1);
        visited[next] = 1;
      }
    }
  }
  cout << max_depth << " " << min_food << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> horses(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> horses[i];
  }
  // 边
  vector<unordered_set<int>> adjList(n + 1);
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adjList[x].insert(y);
    adjList[y].insert(x);
  }
  solve(n, m, horses, adjList);
  return 0;
}
