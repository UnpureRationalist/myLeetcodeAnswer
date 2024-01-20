#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& heights) {
    int result = 0;
    int left = 0, right = heights.size() - 1;
    int left_max = heights[left], right_max = heights[right];

    while (left < right) {
      left_max = max(left_max, heights[left]);
      right_max = max(right_max, heights[right]);
      if (left_max < right_max) {
        result += left_max - heights[left];
        ++left;
      } else {
        result += right_max - heights[right];
        --right;
      }
    }

    return result;
  }
};