#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre_muti(n, 1);
    vector<int> post_muti(n, 1);
    for (int i = 1; i < n; ++i) {
      pre_muti[i] = pre_muti[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
      post_muti[i] = post_muti[i + 1] * nums[i + 1];
    }
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
      result[i] = pre_muti[i] * post_muti[i];
    }
    return result;
  }
};

class Solution2 {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    for (int i = 1; i < n; ++i) {
      result[i] = result[i - 1] * nums[i - 1];
    }
    int post_muti_res = 1;
    for (int i = n - 1; i >= 0; --i) {
      if (i != n - 1) {
        post_muti_res *= nums[i + 1];
      }
      result[i] *= post_muti_res;
    }
    return result;
  }
};