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
    int idx = 0;
    for (int i = 0; i < n;) {
      int j = i + 1;
      while (j < n && nums[j] == nums[i]) {
        ++j;
      }
      nums[idx++] = nums[i];
      i = j;
    }
    return idx;
  }
};

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int idx = 1;
    for (int i = 1; i < n; ++i) {
      if (nums[idx - 1] != nums[i]) {
        nums[idx++] = nums[i];
      }
    }
    return idx;
  }
};
