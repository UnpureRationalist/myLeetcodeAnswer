#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    // 水平交换
    int i = 0, j = n - 1;
    while (i < j) {
      swap(matrix[i], matrix[j]);
      ++i;
      --j;
    }
    // 对角线交换
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < row; ++col) {
        swap(matrix[row][col], matrix[col][row]);
      }
    }
  }
};
