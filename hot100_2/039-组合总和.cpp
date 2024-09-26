#include <bits/stdc++.h>
using namespace std;

class Solution {
  int n;
  vector<vector<int>> result;

  vector<int> tmp;

  void dfs(int depth, const vector<int> &candidates, int sum, int target) {
    if (sum == target) {
      result.push_back(tmp);
      return;
    }
    if (sum > target) {
      return;
    }
    if (depth == n) {
      return;
    }
    // 不选
    dfs(depth + 1, candidates, sum, target);

    // 选
    tmp.push_back(candidates[depth]);
    dfs(depth, candidates, sum + candidates[depth], target);
    tmp.pop_back();
  }

 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    result.clear();
    tmp.clear();
    n = candidates.size();
    if (n == 0) {
      return result;
    }

    dfs(0, candidates, 0, target);

    return result;
  }
};
