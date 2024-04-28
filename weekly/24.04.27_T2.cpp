#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long numberOfRightTriangles(vector<vector<int>> &grid) {
    // 统计每一行 1 的数量 和 每一列 1 的数量
    int rows = grid.size();
    int cols = grid[0].size();
    vector<long long> rowCount(rows, 0);
    vector<long long> colCount(cols, 0);
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (grid[row][col] == 1) {
          rowCount[row]++;
          colCount[col]++;
        }
      }
    }
    long long ans = 0;
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (grid[row][col] == 1) {  // 以 grid[row][col] 作为直角三角形直角顶点的数量
          ans += (rowCount[row] - 1) * (colCount[col] - 1);
        }
      }
    }
    return ans;
  }
};
