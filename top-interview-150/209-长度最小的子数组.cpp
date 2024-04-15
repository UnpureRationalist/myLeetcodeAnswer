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
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    int left = 0, right = 1;
    int sum = nums[left];
    int ans = sum >= target ? 1 : n + 1;
    while (right < n) {
      while (right < n && sum < target) {
        sum += nums[right];
        ++right;
      }
      if (sum < target) {
        break;
      }
      while (left < right && sum >= target) {
        ans = min(ans, right - left);
        sum -= nums[left];
        ++left;
      }
    }
    return ans == n + 1 ? 0 : ans;
  }
};
