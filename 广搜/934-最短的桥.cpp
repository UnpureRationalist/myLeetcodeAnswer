#include <bits/stdc++.h>
using namespace std;

class Solution {
  int rows;
  int cols;
  static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool legal(int x, int y) { return x >= 0 && x < rows && y >= 0 && y < cols; }

  void dfs(queue<pair<int, int>> &q, int x, int y, vector<vector<char>> &visited, const vector<vector<int>> &grid) {
    visited[x][y] = 1;
    q.emplace(x, y);
    for (int i = 0; i < 4; ++i) {
      int nx = x + dirs[i][0];
      int ny = y + dirs[i][1];
      if (legal(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 1) {
        dfs(q, nx, ny, visited, grid);
      }
    }
  }

 public:
  int shortestBridge(vector<vector<int>> &grid) {
    rows = grid.size();
    cols = grid[0].size();
    vector<vector<char>> visited(rows, vector<char>(cols, 0));
    queue<pair<int, int>> q;
    for (int i = 0; q.empty() && i < rows; ++i) {
      for (int j = 0; q.empty() && j < cols; ++j) {
        if (grid[i][j] == 1) {
          dfs(q, i, j, visited, grid);
        }
      }
    }
    // bfs
    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int nx = x + dirs[i][0];
          int ny = y + dirs[i][1];
          if (legal(nx, ny) && !visited[nx][ny]) {
            if (grid[nx][ny] == 1) {
              return step;
            }
            q.emplace(nx, ny);
            visited[nx][ny] = 1;
          }
        }
      }
      ++step;
    }
    return step;
  }
};
