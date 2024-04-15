#include "header.h"

class Solution {
  bool equal(TreeNode *ltree, TreeNode *rtree) {
    if (ltree == nullptr && rtree == nullptr) {
      return true;
    }
    if (!(ltree && rtree)) {
      return false;
    }
    if (ltree->val != rtree->val) {
      return false;
    }
    return equal(ltree->left, rtree->right) && equal(ltree->right, rtree->left);
  }

 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return equal(root->left, root->right);
  }
};
