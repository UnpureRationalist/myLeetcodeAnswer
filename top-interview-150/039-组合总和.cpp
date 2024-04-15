#include "header.h"

class Solution {
  int n;
  vector<vector<int>> ans;
  vector<int> cur;

  void dfs(vector<int> &candidates, int target, int i) {
    if (target == 0) {
      ans.push_back(cur);
      return;
    }
    if (target < 0 || i >= n) {
      return;
    }

    // 选
    cur.push_back(candidates[i]);
    dfs(candidates, target - candidates[i], i);
    cur.pop_back();

    // 不选
    dfs(candidates, target, i + 1);
  }

 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    n = candidates.size();
    ans.clear();
    cur.clear();
    dfs(candidates, target, 0);
    return ans;
  }
};
