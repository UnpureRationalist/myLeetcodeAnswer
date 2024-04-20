#include "header.h"

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    // 从右上角开始查找
    int row = 0;
    int col = cols - 1;
    while (row < rows && col >= 0) {
      int value = matrix[row][col];
      if (value == target) {
        return true;
      }
      if (value < target) {
        ++row;
      } else {
        --col;
      }
    }
    return false;
  }
};

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    // 从左下角开始查找
    int row = rows - 1;
    int col = 0;
    while (row >= 0 && col < cols) {
      int value = matrix[row][col];
      if (value == target) {
        return true;
      }
      if (value < target) {
        ++col;
      } else {
        --row;
      }
    }
    return false;
  }
};