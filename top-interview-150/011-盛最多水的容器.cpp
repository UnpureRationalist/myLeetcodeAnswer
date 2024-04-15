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
  int maxArea(vector<int> &height) {
    int n = height.size();
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j) {
      ans = max(ans, min(height[i], height[j]) * (j - i));
      if (height[i] > height[j]) {
        --j;
      } else {
        ++i;
      }
    }
    return ans;
  }
};
