#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> result;
  vector<int> temp;
  int n;

  void dfs(int idx, int target, vector<int> &candidate) {
    if (idx >= n) {
      return;
    }

    if (target == 0) {
      result.emplace_back(temp);
      return;
    }

    // 不选择当前数字
    dfs(idx + 1, target, candidate);

    // 选择
    if (target - candidate[idx] >= 0) {
      temp.emplace_back(candidate[idx]);
      dfs(idx, target - candidate[idx], candidate);
      temp.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    result.clear();
    temp.clear();
    n = candidates.size();

    dfs(0, target, candidates);

    return result;
  }
};

class Solution {
  vector<int> cur;

 public:
  void DFS(int begin, int sum, vector<int> &candidates, int target, vector<vector<int>> &res) {
    if (sum == target) {
      res.push_back(cur);
      return;
    }
    if (sum > target) {
      return;
    }
    for (int i = begin; i < candidates.size(); i++) {
      cur.push_back(candidates[i]);
      DFS(i, sum + candidates[i], candidates, target, res);
      cur.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    DFS(0, 0, candidates, target, res);
    return res;
  }
};
