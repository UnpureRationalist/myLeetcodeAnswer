#include "TreeNode.h"

class Solution {
  bool isSymmetric(TreeNode *lTree, TreeNode *rTree) {
    if (lTree == nullptr && rTree == nullptr) {
      return true;
    }
    if (lTree && rTree) {
      if (lTree->val != rTree->val) {
        return false;
      }
      return isSymmetric(lTree->left, rTree->right) && isSymmetric(lTree->right, rTree->left);
    }
    return false;
  }

 public:
  bool isSymmetric(TreeNode *root) { return isSymmetric(root->left, root->right); }
};
