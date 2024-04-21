#include "header.h"

class Solution {
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart == preEnd) {
      return new TreeNode(preorder[preStart]);
    }
    if (preStart > preEnd) {
      return nullptr;
    }
    int root_value = preorder[preStart];
    int idx_inorder = std::find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, root_value) - inorder.begin();
    int ltree_size = idx_inorder - inStart;
    TreeNode *root = new TreeNode(root_value);
    root->left = buildTree(preorder, inorder, preStart + 1, preStart + ltree_size, inStart, idx_inorder - 1);
    root->right = buildTree(preorder, inorder, preStart + ltree_size + 1, preEnd, idx_inorder + 1, inEnd);
    return root;
  }

 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    return buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};
