#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
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
 public:
  unordered_map<int, TreeNode *> fa;
  unordered_map<int, bool> vis;
  void dfs(TreeNode *root) {
    if (root->left != nullptr) {
      fa[root->left->val] = root;
      dfs(root->left);
    }
    if (root->right != nullptr) {
      fa[root->right->val] = root;
      dfs(root->right);
    }
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    fa[root->val] = nullptr;
    dfs(root);
    while (p != nullptr) {
      vis[p->val] = true;
      p = fa[p->val];
    }
    while (q != nullptr) {
      if (vis[q->val]) return q;
      q = fa[q->val];
    }
    return nullptr;
  }
};
