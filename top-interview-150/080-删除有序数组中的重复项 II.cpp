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
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) {
      return n;
    }
    int idx = 2;
    for (int i = 2; i < n; ++i) {
      if (nums[idx - 1] != nums[i] || nums[idx - 1] != nums[idx - 2]) {
        nums[idx++] = nums[i];
      }
    }
    return idx;
  }
};
