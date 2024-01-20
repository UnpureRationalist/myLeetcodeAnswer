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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool helper(TreeNode *root, long long lower, long long upper) {
    if (root == nullptr) {
      return true;
    }
    if (root->val <= lower || root->val >= upper) {
      return false;
    }
    return helper(root->left, lower, root->val) &&
           helper(root->right, root->val, upper);
  }
  bool isValidBST(TreeNode *root) { return helper(root, LONG_MIN, LONG_MAX); }
};

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    stack<TreeNode *> stack;
    long long inorder = (long long)INT_MIN - 1;

    while (!stack.empty() || root != nullptr) {
      while (root != nullptr) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top();
      stack.pop();
      // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
      if (root->val <= inorder) {
        return false;
      }
      inorder = root->val;
      root = root->right;
    }
    return true;
  }
};
