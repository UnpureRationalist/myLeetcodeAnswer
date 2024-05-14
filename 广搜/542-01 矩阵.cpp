#include <bits/stdc++.h>
using namespace std;

class Solution {
  static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int>> ans(rows, vector<int>(cols, 0));
    vector<vector<char>> visited(rows, vector<char>(cols, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (mat[i][j] == 0) {
          visited[i][j] = 1;
          q.emplace(i, j);
        }
      }
    }
    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        auto [x, y] = q.front();
        q.pop();
        ans[x][y] = step;
        for (int dir = 0; dir < 4; ++dir) {
          int nx = x + dirs[dir][0];
          int ny = y + dirs[dir][1];
          if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny]) {
            q.emplace(nx, ny);
            visited[nx][ny] = 1;
          }
        }
      }
      ++step;
    }
    return ans;
  }
};
