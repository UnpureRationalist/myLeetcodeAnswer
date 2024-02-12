#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> matrix;
    for (int i = 0; i < numRows; ++i) {
      matrix.emplace_back(i + 1, 1);
    }
    for (int i = 2; i < numRows; ++i) {
      for (int j = 1; j < i; ++j) {
        matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
      }
    }
    return matrix;
  }
};
