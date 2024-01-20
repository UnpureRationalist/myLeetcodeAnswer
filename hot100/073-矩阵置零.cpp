#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool first_row_zero = false;
    bool first_col_zero = false;
    for (int col = 0; col < cols; ++col) {
      if (matrix[0][col] == 0) {
        first_row_zero = true;
        break;
      }
    }
    for (int row = 0; row < rows; ++row) {
      if (matrix[row][0] == 0) {
        first_col_zero = true;
        break;
      }
    }
    for (int row = 1; row < rows; ++row) {
      for (int col = 1; col < cols; ++col) {
        if (matrix[row][col] == 0) {
          matrix[0][col] = matrix[row][0] = 0;
        }
      }
    }

    for (int row = 1; row < rows; ++row) {
      for (int col = 1; col < cols; ++col) {
        if (matrix[0][col] == 0 || matrix[row][0] == 0) {
          matrix[row][col] = 0;
        }
      }
    }

    if (first_row_zero) {
      for (int col = 0; col < cols; ++col) {
        matrix[0][col] = 0;
      }
    }
    if (first_col_zero) {
      for (int row = 0; row < rows; ++row) {
        matrix[row][0] = 0;
      }
    }
  }
};