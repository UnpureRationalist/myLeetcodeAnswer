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
  void nextPermutation(vector<int> &nums) { next_permutation(nums.begin(), nums.end()); }
};

class Solution {
 public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;
    for (; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        break;
      }
    }
    int j = i + 1;
    int k = n - 1;
    if (i >= 0) {
      for (; k >= j; --k) {
        if (nums[i] < nums[k]) {
          break;
        }
      }
      swap(nums[i], nums[k]);
    }
    reverse(nums.begin() + j, nums.end());
  }
};
