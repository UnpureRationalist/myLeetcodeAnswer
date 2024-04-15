#include "header.h"

class Solution {
  TreeNode *buildTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe) {
    if (is > ie || ps > pe) {
      return nullptr;
    }
    int target = postorder[pe];
    TreeNode *root = new TreeNode(target);
    int pos = is;
    while (inorder[pos] != target) {
      ++pos;
    }
    int left_tree_size = pos - is;
    root->left = buildTree(inorder, is, pos - 1, postorder, ps, ps + left_tree_size - 1);
    root->right = buildTree(inorder, pos + 1, ie, postorder, ps + left_tree_size, pe - 1);
    return root;
  }

 public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    return buildTree(inorder, 0, n - 1, postorder, 0, n - 1);
  }
};
