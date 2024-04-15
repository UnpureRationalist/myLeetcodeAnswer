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
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n, 1);   // pre[i] 表示 nums[i] 之前的累积
    vector<int> post(n, 1);  // post[i] 表示 nums[i] 之后的累积
    for (int i = 1; i < n; ++i) {
      pre[i] = pre[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
      post[i] = post[i + 1] * nums[i + 1];
    }

    vector<int> ans(n, 1);
    for (int i = 0; i < n; ++i) {
      ans[i] = pre[i] * post[i];
    }
    return ans;
  }
};

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    for (int i = 1; i < n; ++i) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }
    int post_muti = 1;
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = ans[i] * post_muti;
      post_muti *= nums[i];
    }
    return ans;
  }
};
