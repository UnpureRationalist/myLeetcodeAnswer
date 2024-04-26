#include "header.h"

// Leetcode 112. 路径总和
class Solution {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    if (root->val == targetSum && root->left == nullptr && root->right == nullptr) {
      return true;
    }
    int left = targetSum - root->val;
    return hasPathSum(root->left, left) || hasPathSum(root->right, left);
  }
};

// 打印出所有路径
class Solution {
  void hasPathSum(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &ans) {
    if (root == nullptr) {
      return;
    }
    if (root->val == targetSum && root->left == nullptr && root->right == nullptr) {
      path.push_back(root->val);
      ans.emplace_back(path);
      path.pop_back();
      return;
    }

    int left = targetSum - root->val;

    path.push_back(root->val);

    hasPathSum(root->left, left, path, ans);
    hasPathSum(root->right, left, path, ans);

    path.pop_back();
  }

 public:
  vector<vector<int>> getPathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> ans;
    if (root == nullptr) {
      return ans;
    }
    vector<int> path;
    hasPathSum(root, targetSum, path, ans);
    return ans;
  }
};
