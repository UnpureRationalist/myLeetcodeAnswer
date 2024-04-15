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
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int first = 0; first < n; ++first) {
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      int third = n - 1;
      int target = -nums[first];
      for (int second = first + 1; second < n; ++second) {
        if (second > first + 1 && nums[second] == nums[second - 1]) {
          continue;
        }
        while (second < third && nums[second] + nums[third] > target) {
          --third;
        }
        if (second == third) {
          break;
        }
        if (nums[second] + nums[third] == target) {
          ans.emplace_back(vector<int>{nums[first], nums[second], nums[third]});
        }
      }
    }
    return ans;
  }
};
