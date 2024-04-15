#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool first_row_contain_zero = false;
    for (int col = 0; col < cols; ++col) {
      if (matrix[0][col] == 0) {
        first_row_contain_zero = true;
        break;
      }
    }
    // 判断每一列是否含有 0
    for (int col = 0; col < cols; ++col) {
      for (int row = 0; row < rows; ++row) {
        if (matrix[row][col] == 0) {
          matrix[0][col] = 0;
          break;
        }
      }
    }
    // 判断每一行是否含有 0（除了第 1 行）
    for (int row = 1; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (matrix[row][col] == 0) {
          matrix[row][0] = 0;
          break;
        }
      }
    }
    // 列赋 0（除了第 1 列）
    for (int col = 1; col < cols; ++col) {
      if (matrix[0][col] == 0) {
        for (int row = 0; row < rows; ++row) {
          matrix[row][col] = 0;
        }
      }
    }
    // 行赋 0（除了第 1 行）
    for (int row = 1; row < rows; ++row) {
      if (matrix[row][0] == 0) {
        for (int col = 0; col < cols; ++col) {
          matrix[row][col] = 0;
        }
      }
    }
    // 第 1 列赋 0
    if (matrix[0][0] == 0) {
      for (int row = 0; row < rows; ++row) {
        matrix[row][0] = 0;
      }
    }
    // 第 1 行赋 0
    if (first_row_contain_zero) {
      for (int col = 0; col < cols; ++col) {
        matrix[0][col] = 0;
      }
    }
  }
};
