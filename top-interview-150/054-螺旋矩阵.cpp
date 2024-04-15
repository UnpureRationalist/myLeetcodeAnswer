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
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int total = rows * cols;
    vector<int> ans(total, 0);
    int idx = 0;
    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;

    while (idx < total) {
      for (int col = left; col <= right; ++col) {
        ans[idx++] = matrix[top][col];
      }
      for (int row = top + 1; row <= bottom; ++row) {
        ans[idx++] = matrix[row][right];
      }
      if (left < right && top < bottom) {
        for (int col = right - 1; col > left; --col) {
          ans[idx++] = matrix[bottom][col];
        }
        for (int row = bottom; row > top; --row) {
          ans[idx++] = matrix[row][left];
        }
      }
      ++left;
      --right;
      ++top;
      --bottom;
    }
    return ans;
  }
};
