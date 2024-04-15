#include "header.h"

class Solution {
  int result = 0;

  void help(TreeNode *root, int sum) {
    if (root == nullptr) {
      return;
    }
    if (!root->left && !root->right) {
      result += 10 * sum + root->val;
      return;
    }
    help(root->left, 10 * sum + root->val);
    help(root->right, 10 * sum + root->val);
  }

 public:
  int sumNumbers(TreeNode *root) {
    result = 0;
    help(root, 0);
    return result;
  }
};
