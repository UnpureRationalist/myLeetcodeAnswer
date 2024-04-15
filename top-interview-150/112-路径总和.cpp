#include "header.h"

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    int value = root->val;
    if (value == targetSum && !root->left && !root->right) {
      return true;
    }
    return hasPathSum(root->left, targetSum - value) || hasPathSum(root->right, targetSum - value);
  }
};
