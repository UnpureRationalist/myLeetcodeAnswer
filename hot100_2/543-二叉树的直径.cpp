#include "TreeNode.h"

class Solution {
  int ans;
  int depth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int ld = depth(root->left);
    int rd = depth(root->right);
    ans = max(ans, ld + rd);
    return max(ld, rd) + 1;
  }

 public:
  int diameterOfBinaryTree(TreeNode *root) {
    ans = 0;
    depth(root);
    return ans;
  }
};
