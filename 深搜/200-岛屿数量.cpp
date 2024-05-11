#include <bits/stdc++.h>
using namespace std;

class Solution {
  int m;
  int n;

  vector<vector<bool>> visited;

  bool isLegal(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  void dfs(vector<vector<char>> &grid, int x, int y) {
    for (int i = 0; i < 4; ++i) {
      int newx = x + dirs[i][0];
      int newy = y + dirs[i][1];
      if (isLegal(newx, newy) && grid[newx][newy] == '1' && !visited[newx][newy]) {
        visited[newx][newy] = true;
        dfs(grid, newx, newy);
      }
    }
  }

 public:
  int numIslands(vector<vector<char>> &grid) {
    m = grid.size();
    n = grid[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          visited[i][j] = true;
          dfs(grid, i, j);
          ++ans;
        }
      }
    }
    return ans;
  }
};
