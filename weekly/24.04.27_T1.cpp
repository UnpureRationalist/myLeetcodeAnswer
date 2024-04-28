#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool legal(const vector<vector<char>> &grid) {
    int n = grid.size();
    for (int row = 0; row < n - 1; ++row) {
      for (int col = 0; col < n - 1; ++col) {
        if (grid[row][col] == grid[row][col + 1] && grid[row][col] == grid[row + 1][col] &&
            grid[row][col] == grid[row + 1][col + 1]) {
          return true;
        }
      }
    }
    return false;
  }

 public:
  bool canMakeSquare(vector<vector<char>> &grid) {
    int n = grid.size();
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        bool ok = legal(grid);
        if (ok) {
          return true;
        }
        char c = grid[row][col];
        grid[row][col] = c == 'W' ? 'B' : 'W';
        ok = legal(grid);
        if (ok) {
          return true;
        }
        grid[row][col] = c;
      }
    }
    return false;
  }
};