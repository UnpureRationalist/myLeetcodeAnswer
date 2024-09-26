#include <bits/stdc++.h>
using namespace std;

class Solution {
  void printOneCircle(const vector<vector<int>> &matrix, int rows, int rowe, int cols, int cole, vector<int> &result) {
    // first row
    for (int col = cols; col <= cole; ++col) {
      result.push_back(matrix[rows][col]);
    }

    // last column
    if (rows < rowe) {
      for (int row = rows + 1; row <= rowe; ++row) {
        result.push_back(matrix[row][cole]);
      }
    }

    // last row
    if (rows < rowe && cols < cole) {
      for (int col = cole - 1; col >= cols; --col) {
        result.push_back(matrix[rowe][col]);
      }
    }

    // first column
    if (rows < rowe && cols < cole) {
      for (int row = rowe - 1; row > rows; --row) {
        result.push_back(matrix[row][cols]);
      }
    }
  }

 public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    size_t n = rows * cols;
    vector<int> result;
    result.reserve(n);

    int rowstart = 0, rowe = rows - 1;
    int colstart = 0, cole = cols - 1;

    while (result.size() < n) {
      printOneCircle(matrix, rowstart, rowe, colstart, cole, result);
      ++rowstart;
      --rowe;
      ++colstart;
      --cole;
    }

    return result;
  }
};
