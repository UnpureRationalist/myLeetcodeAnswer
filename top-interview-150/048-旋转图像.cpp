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
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    // 水平翻转
    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < n; ++j) {
        swap(matrix[i][j], matrix[n - i - 1][j]);
      }
    }
    // 主对角线翻转
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
