#include "header.h"

class Solution {
  int n;
  vector<vector<int>> ans;
  vector<int> temp;
  vector<char> visited;

  void dfs(vector<int> &nums, int depth) {
    if (n == depth) {
      ans.push_back(temp);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        visited[i] = 1;
        temp.push_back(nums[i]);
        dfs(nums, depth + 1);
        visited[i] = 0;
        temp.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> permute(vector<int> &nums) {
    n = nums.size();
    ans.clear();
    temp.clear();
    visited.resize(n, false);
    dfs(nums, 0);
    return ans;
  }
};
