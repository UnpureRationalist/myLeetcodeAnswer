#include "header.h"

class Solution {
  int ans;
  int k;
  int count;

  void inOrder(TreeNode *root) {
    if (root == nullptr || count >= k) {
      return;
    }
    inOrder(root->left);
    ++count;
    if (count == k) {
      ans = root->val;
    }
    inOrder(root->right);
  }

 public:
  int kthSmallest(TreeNode *root, int k) {
    this->k = k;
    count = 0;
    inOrder(root);
    return ans;
  }
};
