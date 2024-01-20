#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  int depth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + max(depth(root->left), depth(root->right));
  }

 public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int cur = depth(root->left) + depth(root->right);
    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    return max(cur, max(left, right));
  }
};

class Solution {
  int ans;
  int depth(TreeNode *rt) {
    if (rt == NULL) {
      return 0;  // 访问到空节点了，返回0
    }
    int L = depth(rt->left);   // 左儿子为根的子树的深度
    int R = depth(rt->right);  // 右儿子为根的子树的深度
    ans = max(ans, L + R);     // 计算d_node即L+R+1 并更新ans
    return max(L, R) + 1;      // 返回该节点为根的子树的深度
  }

 public:
  int diameterOfBinaryTree(TreeNode *root) {
    ans = 0;
    depth(root);
    return ans;
  }
};
