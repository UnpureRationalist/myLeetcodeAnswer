#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x{0};
  int y{0};

  Point() = default;

  Point(int _x, int _y) : x(_x), y(_y) {}

  bool operator==(const Point &rop) const { return this->x == rop.x && this->y == rop.y; }
};

int pointDistance(const Point &lop, const Point &rop) { return abs(lop.x - rop.x) + abs(lop.y - rop.y); }

int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool legalPosition(int x, int y, int rows, int cols) { return x >= 1 && x <= rows && y >= 1 && y <= cols; }

// BFS 求多源最短路径
vector<vector<int>> getMinDistance(int rows, int cols, const vector<vector<char>> &matrix,
                                   const vector<Point> &potatos) {
  vector<vector<int>> dis(rows + 1, vector<int>(cols + 1, -1));
  queue<Point> q;
  for (const auto &[x, y] : potatos) {
    q.emplace(x, y);
    dis[x][y] = 0;
  }
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nextx = x + dirs[i][0];
      int nexty = y + dirs[i][1];
      if (legalPosition(nextx, nexty, rows, cols) && dis[nextx][nexty] == -1 && matrix[nextx][nexty] == 0) {
        dis[nextx][nexty] = 1 + dis[x][y];
        q.emplace(nextx, nexty);
      }
    }
  }
  return dis;
}

bool check(int rows, int cols, const vector<vector<char>> &matrix, const vector<vector<int>> &dis, const Point &from,
           const Point &to, int min_distance) {
  if (dis[from.x][from.y] < min_distance) {
    return false;
  }
  vector<vector<char>> visited(rows + 1, vector<char>(cols + 1, 0));
  queue<Point> q;
  q.push(from);
  visited[from.x][from.y] = 1;
  while (!q.empty()) {
    Point current = q.front();
    q.pop();
    if (current == to) {
      return true;  // 到达终点
    }
    int x = current.x;
    int y = current.y;
    for (int i = 0; i < 4; ++i) {
      int nextx = x + dirs[i][0];
      int nexty = y + dirs[i][1];
      if (legalPosition(nextx, nexty, rows, cols) && !visited[nextx][nexty] && matrix[nextx][nexty] == 0 &&
          dis[nextx][nexty] >= min_distance) {
        visited[nextx][nexty] = 1;
        q.emplace(nextx, nexty);
      }
    }
  }
  return false;
}

void solve(int rows, int cols, const vector<vector<char>> &matrix, const vector<vector<int>> &dis, const Point &from,
           const Point &to) {
  int ans = 1;
  int left = 0;
  int right = rows + cols;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    bool ok = check(rows, cols, matrix, dis, from, to, mid);
    if (ok && !check(rows, cols, matrix, dis, from, to, mid + 1)) {
      ans = mid;
      break;
    }
    if (ok) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int rows, cols, k;
  cin >> rows >> cols >> k;
  vector<vector<char>> matrix(rows + 1, vector<char>(cols + 1, 0));
  vector<Point> potatos;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    matrix[x][y] = 1;
    potatos.emplace_back(x, y);
  }
  Point from, to;
  cin >> from.x >> from.y >> to.x >> to.y;
  auto dis = getMinDistance(rows, cols, matrix, potatos);
  solve(rows, cols, matrix, dis, from, to);
  return 0;
}
