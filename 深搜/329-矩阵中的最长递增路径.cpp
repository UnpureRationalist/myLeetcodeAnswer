#include <bits/stdc++.h>
using namespace std;

class Solution {
  int rows;
  int cols;

  vector<vector<int>> dp;

  int ans = 0;

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool legal(int x, int y) { return x >= 0 && x < rows && y >= 0 && y < cols; }

  int dfs(int x, int y, const vector<vector<int>> &matrix) {
    if (dp[x][y] != -1) {
      return dp[x][y];
    }

    int cur = matrix[x][y];

    int max_sub = 0;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dirs[i][0];
      int ny = y + dirs[i][1];
      if (legal(nx, ny) && matrix[nx][ny] > cur) {
        max_sub = max(max_sub, dfs(nx, ny, matrix));
      }
    }
    dp[x][y] = max_sub + 1;
    ans = max(ans, dp[x][y]);
    return dp[x][y];
  }

 public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    rows = matrix.size();
    cols = matrix[0].size();

    dp.resize(rows, vector<int>(cols, -1));

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        dfs(i, j, matrix);
      }
    }

    return ans;
  }
};
