#include "header.h"

class Solution {
  TreeNode *buildTree(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie) {
    if (ps > pe || is > ie) {
      return nullptr;
    }
    int target = preorder[ps];
    TreeNode *root = new TreeNode(target);
    int pos = is;
    while (inorder[pos] != target) {
      ++pos;
    }
    int left_tree_size = pos - is;
    root->left = buildTree(preorder, ps + 1, ps + left_tree_size, inorder, is, pos - 1);
    root->right = buildTree(preorder, ps + left_tree_size + 1, pe, inorder, pos + 1, ie);
    return root;
  }

 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    return buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
  }
};
