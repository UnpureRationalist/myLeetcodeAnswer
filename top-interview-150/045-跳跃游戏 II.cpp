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
  int jump(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      return 0;
    }
    int right = 0;
    int ans = 0;
    int cur_step_end = 0;
    for (int i = 0; i < n - 1; ++i) {
      right = max(right, i + nums[i]);
      if (i == cur_step_end) {
        ++ans;
        cur_step_end = right;
      }
    }
    return ans;
  }
};
