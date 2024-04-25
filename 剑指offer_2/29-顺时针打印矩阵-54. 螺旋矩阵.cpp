#include "header.h"

class Solution {
  void printMatrixInCircle(const vector<vector<int>> &matrix, int rows, int cols, int start, vector<int> &ans) {
    int endRow = rows - 1 - start;
    int endCol = cols - 1 - start;
    // 从左到右打印一行
    for (int col = start; col <= endCol; ++col) {
      ans.emplace_back(matrix[start][col]);
    }
    // 从上到下打印一列
    for (int row = start + 1; row <= endRow; ++row) {
      ans.emplace_back(matrix[row][endCol]);
    }
    // 从右到左打印一行
    if (endRow > start) {
      for (int col = endCol - 1; col >= start; --col) {
        ans.emplace_back(matrix[endRow][col]);
      }
    }
    // 从下到上打印一列
    if (endCol > start) {
      for (int row = endRow - 1; row > start; --row) {
        ans.emplace_back(matrix[row][start]);
      }
    }
  }

 public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int start = 0;  // 从位置 matrix[start][start] 开始顺时针打印一圈
    vector<int> ans;
    ans.reserve(rows * cols);
    while (2 * start < rows && 2 * start < cols) {
      printMatrixInCircle(matrix, rows, cols, start, ans);
      ++start;
    }
    return ans;
  }
};
