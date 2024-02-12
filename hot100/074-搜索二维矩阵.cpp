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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    int low = 0, high = rows * cols - 1;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      int x = matrix[mid / cols][mid % cols];
      if (x < target) {
        low = mid + 1;
      } else if (x > target) {
        high = mid - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
