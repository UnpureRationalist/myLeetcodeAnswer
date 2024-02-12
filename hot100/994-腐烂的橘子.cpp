#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  int rows;
  int cols;

  bool legal(int i, int j) { return i >= 0 && i < rows && j >= 0 && j < cols; }

 public:
  int orangesRotting(vector<vector<int>> &grid) {
    rows = grid.size();
    cols = grid[0].size();
    queue<std::pair<int, int>> q;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 2) {
          q.emplace(i, j);
        }
      }
    }
    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      bool has_val = false;
      while (size--) {
        auto [i, j] = q.front();
        q.pop();
        for (auto &vec : dirs) {
          int i_new = i + vec[0];
          int j_new = j + vec[1];
          if (legal(i_new, j_new)) {
            if (grid[i_new][j_new] == 1) {
              has_val = true;
              grid[i_new][j_new] = 2;
              q.emplace(i_new, j_new);
            }
          }
        }
      }
      if (has_val) {
        ++step;
      }
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }
    return step;
  }
};