#include <bits/stdc++.h>
using namespace std;

int cols, rows;

const int MAX = 1e9;

int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Node {
  int x;
  int y;
  int weight;

  Node() = default;

  Node(int _x, int _y, int _weight) : x(_x), y(_y), weight(_weight) {}

  bool operator<(const Node &rop) const { return this->weight > rop.weight; }
};

bool legal(int x, int y) { return x >= 0 && x < rows && y >= 0 && y < cols; }

void solve(int x, int y, const vector<vector<int>> &matrix) {
  vector<vector<int>> dis(rows, vector<int>(cols, MAX));
  vector<vector<char>> visited(rows, vector<char>(cols, 0));
  priority_queue<Node> q;
  q.emplace(x, y, 0);
  dis[x][y] = 0;
  while (!q.empty()) {
    auto [x, y, weight] = q.top();
    q.pop();
    if (visited[x][y]) {
      continue;
    }
    visited[x][y] = 1;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dirs[dir][0];
      int ny = y + dirs[dir][1];
      if (legal(nx, ny) && !visited[nx][ny] && matrix[nx][ny] != 0 && dis[x][y] + matrix[x][y] < dis[nx][ny]) {
        dis[nx][ny] = dis[x][y] + matrix[x][y];
        q.emplace(nx, ny, dis[nx][ny]);
      }
    }
  }
  int ans = 0;
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (matrix[row][col] != 0 && dis[row][col] == MAX) {
        cout << -1 << endl;
        return;
      }
      if (matrix[row][col] != 0) {
        ans = max(ans, dis[row][col]);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> cols >> rows;
  int x, y;
  cin >> x >> y;
  vector<vector<int>> matrix(rows, vector<int>(cols));
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> matrix[i][j];
    }
  }
  solve(x, y, matrix);
  return 0;
}
