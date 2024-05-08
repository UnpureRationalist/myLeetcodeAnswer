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

bool legalPosition(int x, int y, int rows, int cols) { return x >= 0 && x < rows && y >= 0 && y < cols; }

// BFS 求多源最短路径
vector<vector<int>> getMinDistance(int rows, int cols, const vector<vector<int>> &matrix,
                                   const vector<Point> &potatos) {
  vector<vector<int>> dis(rows, vector<int>(cols, -1));
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

bool check(int rows, int cols, const vector<vector<int>> &matrix, const vector<vector<int>> &dis, const Point &from,
           const Point &to, int min_distance) {
  if (dis[from.x][from.y] < min_distance) {
    return false;
  }
  if (matrix[from.x][from.y]) {
    return false;
  }
  vector<vector<char>> visited(rows, vector<char>(cols, 0));
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

int solve(int rows, int cols, const vector<vector<int>> &matrix, const vector<vector<int>> &dis, const Point &from,
          const Point &to) {
  int ans = 0;
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
  return ans;
}
class Solution {
 public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    Point from{0, 0};
    Point to(rows - 1, cols - 1);
    vector<Point> thieves;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 1) {
          thieves.emplace_back(i, j);
        }
      }
    }
    auto dis = getMinDistance(rows, cols, grid, thieves);
    return solve(rows, cols, grid, dis, from, to);
  }
};

// 题解
class Solution {
  static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

 public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<pair<int, int>> q;
    vector<vector<int>> dis(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          q.emplace_back(i, j);
          dis[i][j] = 0;
        }
      }
    }

    vector<vector<pair<int, int>>> groups = {q};
    while (!q.empty()) {  // 多源 BFS
      vector<pair<int, int>> nq;
      for (auto &[i, j] : q) {
        for (auto &d : dirs) {
          int x = i + d[0], y = j + d[1];
          if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] < 0) {
            nq.emplace_back(x, y);
            dis[x][y] = groups.size();
          }
        }
      }
      groups.push_back(nq);  // 相同 dis 分组记录
      q = move(nq);
    }

    // 并查集模板
    vector<int> fa(n * n);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&](int x) -> int { return fa[x] == x ? x : fa[x] = find(fa[x]); };

    for (int ans = (int)groups.size() - 2; ans > 0; ans--) {
      for (auto &[i, j] : groups[ans]) {
        for (auto &d : dirs) {
          int x = i + d[0], y = j + d[1];
          if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] >= dis[i][j]) fa[find(x * n + y)] = find(i * n + j);
        }
      }
      if (find(0) == find(n * n - 1))  // 写这里判断更快些
        return ans;
    }
    return 0;
  }
};
