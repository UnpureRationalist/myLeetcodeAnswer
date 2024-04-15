#include "header.h"

class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode *left = root->left, *right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);
    return root;
  }
};
