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
  int majorityElement(vector<int>& nums) {
    int ans = nums[0];
    int votes = 0;
    for (const auto& num : nums) {
      if (votes == 0) {
        ans = num;
      }
      votes += ans == num ? 1 : -1;
    }
    return ans;
  }
};
