#include <bits/stdc++.h>
using namespace std;

class Solution {
  int rows;
  int cols;

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool legal(int row, int col) { return row >= 0 && row < rows && col >= 0 && col < cols; }

 public:
  int orangesRotting(vector<vector<int>> &grid) {
    int step = 0;

    rows = grid.size();
    cols = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<char>> visited(rows, vector<char>(cols, 0));
    int cnt = 0;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 2) {
          visited[i][j] = 1;
          q.emplace(i, j);
        } else if (grid[i][j] == 1) {
          ++cnt;
        }
      }
    }

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        int row, col;
        std::tie(row, col) = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
          int nx = row + dirs[dir][0];
          int ny = col + dirs[dir][1];
          if (legal(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            --cnt;
            q.emplace(nx, ny);
          }
        }
      }
      if (!q.empty()) {
        ++step;
      }
    }

    return cnt > 0 ? -1 : step;
  }
};
