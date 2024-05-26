#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  void dfs(TreeNode *root, unordered_map<TreeNode *, array<int, 2>> &dp) {
    if (root == nullptr) {
      return;
    }
    dp[root][1] = root->val;
    for (auto &child : {root->left, root->right}) {
      dfs(child, dp);
      dp[root][0] += max(dp[child][0], dp[child][1]);
      dp[root][1] += dp[child][0];
    }
  }

 public:
  int rob(TreeNode *root) {
    unordered_map<TreeNode *, array<int, 2>> dp;
    dp[nullptr] = {0, 0};
    dfs(root, dp);
    return max(dp[root][0], dp[root][1]);
  }
};
