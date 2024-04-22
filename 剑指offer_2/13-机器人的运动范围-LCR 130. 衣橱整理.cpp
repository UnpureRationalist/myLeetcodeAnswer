#include "header.h"

class Solution {
  int digitSum(int n) {
    int sum = 0;
    while (n) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }

  int rows;
  int cols;

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  vector<vector<char>> visited;

  void dfs(int row, int col, int cnt, int &count) {
    visited[row][col] = 1;
    if (digitSum(row) + digitSum(col) <= cnt) {
      ++count;
    } else {
      return;
    }
    for (int i = 0; i < 4; ++i) {
      int next_row = row + dirs[i][0];
      int next_col = col + dirs[i][1];
      if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols && !visited[next_row][next_col]) {
        dfs(next_row, next_col, cnt, count);
      }
    }
  }

 public:
  int wardrobeFinishing(int m, int n, int cnt) {
    rows = m;
    cols = n;
    visited.resize(rows, vector<char>(cols, 0));
    int ans = 0;
    dfs(0, 0, cnt, ans);
    return ans;
  }
};
