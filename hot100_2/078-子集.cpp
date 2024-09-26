#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> tmp;
  vector<vector<int>> result;
  int n;

  void dfs(int depth, const vector<int> &nums) {
    if (depth == n) {
      result.push_back(tmp);
      return;
    }
    // 不选
    dfs(depth + 1, nums);

    // 选
    tmp.push_back(nums[depth]);
    dfs(depth + 1, nums);
    tmp.pop_back();
  }

 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    n = nums.size();
    result.clear();
    tmp.clear();

    dfs(0, nums);

    return result;
  }
};
