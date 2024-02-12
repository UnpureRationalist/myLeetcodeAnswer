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
  void sortColors(vector<int> &nums) {
    vector<int> mp(3, 0);
    for (const auto &num : nums) {
      mp[num]++;
    }
    int idx = 0;
    int n = mp.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < mp[i]; ++j) {
        nums[idx++] = i;
      }
    }
    return;
  }
};
