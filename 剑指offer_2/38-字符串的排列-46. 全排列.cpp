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

// 有重复数字的情况：47. 全排列 II
class Solution {
  vector<char> vis;

  void backtrack(vector<int> &nums, vector<vector<int>> &ans, int idx, vector<int> &perm) {
    if (idx == nums.size()) {
      ans.emplace_back(perm);
      return;
    }
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
        continue;  // 去重
      }
      perm.emplace_back(nums[i]);
      vis[i] = 1;
      backtrack(nums, ans, idx + 1, perm);
      vis[i] = 0;
      perm.pop_back();
    }
  }

 public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> perm;
    vis.resize(nums.size());
    sort(nums.begin(), nums.end());
    backtrack(nums, ans, 0, perm);
    return ans;
  }
};
