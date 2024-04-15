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
  int trap(vector<int> &height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int left_max = height[0], right_max = height[right];
    int ans = 0;
    while (left < right) {
      left_max = max(left_max, height[left]);
      right_max = max(right_max, height[right]);
      if (left_max < right_max) {
        ans += left_max - height[left];
        ++left;
      } else {
        ans += right_max - height[right];
        --right;
      }
    }
    return ans;
  }
};
