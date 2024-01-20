#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  TreeNode *build(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie) {
    if (ps > pe) {
      return nullptr;
    }
    if (ps == pe) {
      return new TreeNode(preorder[ps]);
    }
    int idx = is;
    for (; idx <= ie; ++idx) {
      if (inorder[idx] == preorder[ps]) {
        break;
      }
    }
    TreeNode *node = new TreeNode(preorder[ps]);
    int left_tree_size = idx - is;
    int right_tree_size = ie - idx;
    node->left = build(preorder, ps + 1, ps + left_tree_size, inorder, is, idx - 1);
    node->right = build(preorder, ps + left_tree_size + 1, pe, inorder, idx + 1, ie);
    return node;
  }

 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    if (n == 0) {
      return nullptr;
    }
    return build(preorder, 0, n - 1, inorder, 0, n - 1);
  }
};