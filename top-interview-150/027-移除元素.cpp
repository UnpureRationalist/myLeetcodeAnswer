#include <algorithm>
#include <climits>
#include <cmath>
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
  int removeElement(vector<int>& nums, int val) {
    int idx = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] != val) {
        nums[idx++] = nums[i];
      }
    }
    return idx;
  }
};
