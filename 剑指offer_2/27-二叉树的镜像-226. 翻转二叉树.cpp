#include "header.h"

class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode *left_child = root->left;
    TreeNode *right_child = root->right;
    root->left = invertTree(right_child);
    root->right = invertTree(left_child);
    return root;
  }
};
