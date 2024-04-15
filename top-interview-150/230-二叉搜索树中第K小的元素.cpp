#include "header.h"

class Solution {
  int number_ = 0;
  int ans_ = 0;
  int k_ = 1;

  void helper(TreeNode *root) {
    if (!root) {
      return;
    }
    helper(root->left);
    ++number_;
    if (number_ == k_) {
      ans_ = root->val;
      return;
    }
    helper(root->right);
  }

 public:
  int kthSmallest(TreeNode *root, int k) {
    number_ = 0;
    ans_ = 0;
    k_ = k;
    helper(root);
    return ans_;
  }
};
