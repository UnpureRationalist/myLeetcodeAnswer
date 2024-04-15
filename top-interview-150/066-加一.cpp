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
  vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    vector<int> ans(n + 1, 0);
    int pre = 0;
    int idx = 0;
    for (int i = n - 1; i >= 0; --i) {
      int sum = digits[i] + pre + (i == n - 1 ? 1 : 0);
      pre = sum / 10;
      ans[idx++] = sum % 10;
    }
    if (pre) {
      ans[idx] = pre;
    } else {
      ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
