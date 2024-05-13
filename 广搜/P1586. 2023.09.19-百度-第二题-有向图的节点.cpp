#include <bits/stdc++.h>
using namespace std;

struct Node {
  int id;
  long long step;

  Node(int _id, long long _step) : id(_id), step(_step) {}
};

void solve(int n, long long k, const vector<int> &edges) {
  vector<char> visited(n + 1, 0);
  queue<Node> q;
  q.emplace(1, 0);
  visited[1] = 1;
  set<int> accessible;
  while (!q.empty()) {
    auto [cur, step] = q.front();
    q.pop();
    accessible.insert(cur);
    if (!visited[edges[cur]] && step < k) {
      q.emplace(edges[cur], step + 1);
      visited[edges[cur]] = 1;
    }
  }
  bool first = true;
  for (const auto &elem : accessible) {
    if (first) {
      cout << elem;
      first = false;
    } else {
      cout << " " << elem;
    }
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> edges(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> edges[i];
  }
  solve(n, k, edges);
  return 0;
}
