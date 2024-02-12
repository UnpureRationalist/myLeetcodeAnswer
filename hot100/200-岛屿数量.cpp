#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  vector<vector<bool>> visited;
  int rows;
  int cols;

  vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  void dfs(int i, int j, vector<vector<char>> &grid) {
    visited[i][j] = true;
    grid[i][j] = '0';
    for (auto &vec : dirs) {
      int i_new = i + vec[0];
      int j_new = j + vec[1];
      if (i_new >= 0 && i_new < rows && j_new >= 0 && j_new < cols && grid[i_new][j_new] == '1' &&
          !visited[i_new][j_new]) {
        dfs(i_new, j_new, grid);
      }
    }
  }

 public:
  int numIslands(vector<vector<char>> &grid) {
    int nums = 0;
    rows = grid.size();
    cols = grid[0].size();
    visited.resize(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          ++nums;
          dfs(i, j, grid);
        }
      }
    }
    return nums;
  }
};