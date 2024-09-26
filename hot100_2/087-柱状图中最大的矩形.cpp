#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> stk;
    vector<int> left(n, -1);  // left[i] 表示左侧小于 heights[i] 的第一个下标
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && heights[stk.top()] >= heights[i]) {
        stk.pop();
      }
      left[i] = stk.empty() ? -1 : stk.top();
      stk.push(i);
    }
    stk = stack<int>();
    vector<int> right(n, n);
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && heights[stk.top()] > heights[i]) {
        right[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
  }
};
