#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int target = -nums[i];
      int k = n - 1;
      for (int j = i + 1; j < n; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        while (k > j && nums[j] + nums[k] > target) {
          --k;
        }

        if (j == k) {
          break;
        }

        if (nums[j] + nums[k] == target) {
          ans.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
        }
      }
    }

    return ans;
  }
};
