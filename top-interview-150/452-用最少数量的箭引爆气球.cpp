#include "header.h"

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>> &points) {
    if (points.empty()) {
      return 0;
    }
    sort(points.begin(), points.end(), [](const vector<int> &lhs, const vector<int> &rhs) { return lhs[1] < rhs[1]; });
    int arrow_pos = points[0][1];
    int ans = 1;  // 最后一根箭在循环中不会被计算 因此初始化为 1
    for (const vector<int> &balloon : points) {
      if (balloon[0] > arrow_pos) {  // 箭的位置不在当前气球所在区域
        arrow_pos = balloon[1];      // 更新箭的位置
        ++ans;
      }
    }
    return ans;
  }
};
