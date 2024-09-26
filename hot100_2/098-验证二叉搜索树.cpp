#include "TreeNode.h"

class Solution {
  bool helper(TreeNode *root, TreeNode *lower, TreeNode *upper) {
    if (!root) {
      return true;
    }
    if (lower && root->val <= lower->val) {
      return false;
    }
    if (upper && root->val >= upper->val) {
      return false;
    }
    return helper(root->left, lower, root) && helper(root->right, root, upper);
  }

 public:
  bool isValidBST(TreeNode *root) { return helper(root, nullptr, nullptr); }
};
