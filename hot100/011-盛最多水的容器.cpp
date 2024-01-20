#include <vector>
using namespace std;

class Solution {
  int getArea(int left, int right, const vector<int>& heights) {
    return min(heights[left], heights[right]) * (right - left);
  }

 public:
  int maxArea(vector<int>& heights) {
    int left = 0;
    int right = heights.size() - 1;
    int result = 0;
    while (left < right) {
      int area = getArea(left, right, heights);
      if (heights[left] < heights[right]) {
        left++;
      } else if (heights[left] > heights[right]) {
        right--;
      } else {
        left++;
        right--;
      }
      result = max(result, area);
    }
    return result;
  }
};