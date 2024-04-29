#include "header.h"

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

// 变例：Leetcode LCR 176. 判断是否为平衡二叉树
class Solution {
  bool isBalanced(TreeNode *root, int &depth) {
    if (root == nullptr) {
      depth = 0;
      return true;
    }
    int left;
    int right;
    if (isBalanced(root->left, left) && isBalanced(root->right, right)) {
      if (abs(left - right) > 1) {
        return false;
      }
      depth = 1 + max(left, right);
      return true;
    }
    return false;
  }

 public:
  bool isBalanced(TreeNode *root) {
    int depth = 0;
    return isBalanced(root, depth);
  }
};
