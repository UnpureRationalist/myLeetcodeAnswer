#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> matrix(numRows);
    for (int row = 0; row < numRows; ++row) {
      matrix[row].resize(row + 1, 1);
      for (int col = 1; col < row; ++col) {
        matrix[row][col] = matrix[row - 1][col] + matrix[row - 1][col - 1];
      }
    }
    return matrix;
  }
};
