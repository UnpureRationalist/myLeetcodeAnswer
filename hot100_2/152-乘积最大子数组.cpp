#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp_max(n, 1);
    vector<int> dp_min(n, 1);
    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      dp_max[i] = max(nums[i], max(nums[i] * dp_max[i - 1], nums[i] * dp_min[i - 1]));
      dp_min[i] = min(nums[i], min(nums[i] * dp_max[i - 1], nums[i] * dp_min[i - 1]));
    }
    return *max_element(dp_max.begin(), dp_max.end());
  }
};
