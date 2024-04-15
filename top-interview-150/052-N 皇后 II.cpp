#include "header.h"

class Solution {
  int ans = 0;
  vector<int> selected_cols;

  void dfs(int n, int row) {
    if (row == n) {
      ++ans;
      return;
    }
    for (int col = 0; col < n; ++col) {
      bool legal = true;
      for (int select_row = 0; select_row < selected_cols.size(); ++select_row) {
        int select_col = selected_cols[select_row];
        if (col == select_col || abs(row - select_row) == abs(col - select_col)) {
          legal = false;
          break;
        }
      }
      if (legal) {
        selected_cols.push_back(col);
        dfs(n, row + 1);
        selected_cols.pop_back();
      }
    }
  }

 public:
  int totalNQueens(int n) {
    ans = 0;
    selected_cols.clear();
    dfs(n, 0);
    return ans;
  }
};
