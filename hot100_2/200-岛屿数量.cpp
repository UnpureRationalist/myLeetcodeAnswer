#include <bits/stdc++.h>
using namespace std;

class Solution {
  int rows;
  int cols;

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool legal(int row, int col) { return row >= 0 && row < rows && col >= 0 && col < cols; }

  void dfs(int i, int j, const vector<vector<char>> &grid, vector<vector<char>> &visited) {
    visited[i][j] = 1;
    for (int dir = 0; dir < 4; ++dir) {
      int nrow = i + dirs[dir][0];
      int ncol = j + dirs[dir][1];
      if (legal(nrow, ncol) && grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
        dfs(nrow, ncol, grid, visited);
      }
    }
  }

 public:
  int numIslands(vector<vector<char>> &grid) {
    rows = grid.size();
    cols = grid[0].size();
    vector<vector<char>> visited(rows, vector<char>(cols, 0));
    int ans = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          ++ans;
          dfs(i, j, grid, visited);
        }
      }
    }
    return ans;
  }
};
