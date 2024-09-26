#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    // matrix 第 0 行的每个元素，表示每列是否包含 0
    // matrix 第 0 列每个元素（除了第 0 行第 0 列元素），表示每行是否包含 0
    bool first_row_contain_zero = find(matrix[0].begin(), matrix[0].end(), 0) != matrix[0].end();
    // 判断每列是否包含 0
    for (int col = 0; col < cols; ++col) {
      for (int row = 0; row < rows; ++row) {
        if (matrix[row][col] == 0) {
          matrix[0][col] = 0;
          break;
        }
      }
    }
    // 判断每行是否包含 0
    for (int row = 1; row < rows; ++row) {
      auto iter = find(matrix[row].begin(), matrix[row].end(), 0);
      if (iter != matrix[row].end()) {
        matrix[row][0] = 0;
      }
    }
    // 每行填充 0
    for (int row = 1; row < rows; ++row) {
      if (matrix[row][0] == 0) {
        fill(matrix[row].begin(), matrix[row].end(), 0);
      }
    }
    // 每列填充 0
    for (int col = 0; col < cols; ++col) {
      if (matrix[0][col] == 0) {
        for (int row = 1; row < rows; ++row) {
          matrix[row][col] = 0;
        }
      }
    }
    if (first_row_contain_zero) {
      fill(matrix[0].begin(), matrix[0].end(), 0);
    }
  }
};
