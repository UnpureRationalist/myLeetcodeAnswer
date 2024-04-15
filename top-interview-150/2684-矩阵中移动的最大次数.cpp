#include "header.h"

class Solution {
  int dirs[3][2] = {{-1, 1}, {0, 1}, {1, 1}};

 public:
  int maxMoves(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<char>> visited(m, vector<char>(n, 0));
    queue<pair<int, int>> q;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      q.emplace(i, 0);
      int step = 0;
      while (!q.empty()) {
        int num = q.size();
        while (num--) {
          pair<int, int> cur = q.front();
          q.pop();
          int x = cur.first;
          int y = cur.second;
          for (int j = 0; j < 3; ++j) {
            int nx = x + dirs[j][0];
            int ny = y + dirs[j][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] > grid[x][y]) {
              q.emplace(nx, ny);
              visited[nx][ny] = 1;
            }
          }
        }
        ++step;
      }
      ans = max(ans, step);
    }
    return ans - 1;
  }
};
