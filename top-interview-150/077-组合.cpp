#include "header.h"

class Solution {
  void dfs(int n, int k, int start, vector<int> &cur, vector<vector<int>> &ans) {
    // 剪枝：如果剩余元素都选，也达不到 k 个，终止
    if (n - start + 1 + cur.size() < k) {
      return;
    }

    if (cur.size() == k) {
      ans.push_back(cur);
      return;
    }

    // 选
    cur.push_back(start);
    dfs(n, k, start + 1, cur, ans);
    cur.pop_back();

    // 不选
    dfs(n, k, start + 1, cur, ans);
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(n, k, 1, cur, ans);
    return ans;
  }
};
