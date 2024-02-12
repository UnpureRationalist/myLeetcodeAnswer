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
  int jump(vector<int> &nums) {
    int n = nums.size();
    int step = 0;
    int max_pos = 0;
    int cur_step_end = 0;
    for (int i = 0; i < n - 1; ++i) {
      max_pos = max(max_pos, nums[i] + i);
      if (i == cur_step_end) {
        cur_step_end = max_pos;
        ++step;
      }
    }
    return step;
  }
};
