#include <bits/stdc++.h>
using namespace std;

int dfs(int start, int not_allowed, const vector<unordered_set<int>> &adjList, vector<char> &visited) {
  if (start == not_allowed) {
    return 0;
  }
  visited[start] = 1;
  int depth = -1;
  for (const auto &next : adjList[start]) {
    if (next != not_allowed && !visited[next]) {
      depth = max(depth, dfs(next, not_allowed, adjList, visited));
    }
  }
  return depth + 1;
}

int getLength(int start, int not_allowed, const vector<unordered_set<int>> ajdList, int n) {
  vector<char> visited(n + 1, 0);
  return dfs(start, not_allowed, ajdList, visited);
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<unordered_set<int>> adjList(n + 1);
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    adjList[i + 1].insert(x);
    adjList[x].insert(i + 1);
  }
  int x, y;
  cin >> x >> y;
  int len1 = getLength(x, y, adjList, n);
  int len2 = getLength(y, x, adjList, n);
  cout << (1 + len1 + len2) << endl;

  return 0;
}
