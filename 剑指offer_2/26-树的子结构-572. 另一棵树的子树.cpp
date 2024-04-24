#include "header.h"

// Leetcode： 572. 另一棵树的子树
class Solution {
  bool equalTree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr && subRoot == nullptr) {
      return true;
    }
    if (!(root && subRoot)) {
      return false;
    }
    if (root->val != subRoot->val) {
      return false;
    }
    return equalTree(root->left, subRoot->left) && equalTree(root->right, subRoot->right);
  }

 public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr && subRoot == nullptr) {
      return true;
    }
    if (!(root && subRoot)) {
      return false;
    }
    // 都非空
    bool ans = false;
    if (root->val == subRoot->val) {
      ans = equalTree(root->left, subRoot->left) && equalTree(root->right, subRoot->right);
    }
    if (ans) {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};
