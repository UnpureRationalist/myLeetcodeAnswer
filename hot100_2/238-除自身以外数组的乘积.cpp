#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n);
    vector<int> postMult(n, 1);
    for (int i = n - 2; i >= 0; --i) {
      postMult[i] *= postMult[i + 1] * nums[i + 1];
    }
    int preMult = 1;
    for (int i = 0; i < n; ++i) {
      result[i] = preMult * postMult[i];
      preMult *= nums[i];
    }
    return result;
  }
};
