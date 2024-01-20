#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row_e = matrix.size();
    int col_e = matrix[0].size();

    vector<int> result;
    int total = row_e * col_e;
    result.reserve(total);
    int row_s = 0;
    int col_s = 0;
    while (result.size() < total && row_s < row_e && col_s < col_e) {
      // 上 从左到右遍历
      int row = row_s;
      int col = col_s;

      for (col = col_s; col < col_e; col++) {
        result.push_back(matrix[row][col]);
      }
      col = col_e - 1;

      // 右 从上到下遍历
      for (row = row_s + 1; result.size() < total && row < row_e; row++) {
        result.push_back(matrix[row][col]);
      }
      row = row_e - 1;

      // 下 从右到左遍历
      for (col = col_e - 2; result.size() < total && col >= col_s; col--) {
        result.push_back(matrix[row][col]);
      }
      col = col_s;

      // 左 从下向上遍历
      for (row = row_e - 2; result.size() < total && row > row_s; row--) {
        result.push_back(matrix[row][col]);
      }

      // 更新边界
      row_s++;
      row_e--;
      col_s++;
      col_e--;
    }
    return result;
  }
};