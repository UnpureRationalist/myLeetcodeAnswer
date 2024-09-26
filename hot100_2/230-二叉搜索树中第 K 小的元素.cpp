#include "TreeNode.h"

class Solution {
  int ans;
  int count;

  void inorder(TreeNode *root, int k) {
    if (root == nullptr) {
      return;
    }
    if (count >= k) {
      return;
    }
    inorder(root->left, k);
    ++count;
    if (count == k) {
      ans = root->val;
    }
    inorder(root->right, k);
  }

 public:
  int kthSmallest(TreeNode *root, int k) {
    count = 0;
    inorder(root, k);
    return ans;
  }
};
