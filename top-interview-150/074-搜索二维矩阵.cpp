#include "header.h"

class Solution {
  int rows;
  int cols;

  pair<int, int> int2pos(int idx) { return {idx / cols, idx % cols}; }

 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    rows = matrix.size();
    cols = matrix[0].size();
    int left = 0;
    int right = rows * cols - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      auto [x, y] = int2pos(mid);
      if (matrix[x][y] == target) {
        return true;
      }
      if (matrix[x][y] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};
