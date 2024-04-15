#include "header.h"

class Solution {
  int ans = INT32_MAX;
  int last_value = -1;

  void helper(TreeNode *root) {
    if (!root) {
      return;
    }
    helper(root->left);
    if (last_value != -1) {
      ans = min(ans, root->val - last_value);
    }
    last_value = root->val;
    helper(root->right);
  }

 public:
  int getMinimumDifference(TreeNode *root) {
    ans = INT32_MAX;
    last_value = -1;
    helper(root);
    return ans;
  }
};
