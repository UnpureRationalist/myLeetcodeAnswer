#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = rows - 1, col = 0;
    while (row >= 0 && col < cols) {
      if (matrix[row][col] == target) {
        return true;
      }
      if (matrix[row][col] < target) {
        ++col;
      } else {
        --row;
      }
    }
    return false;
  }
};
