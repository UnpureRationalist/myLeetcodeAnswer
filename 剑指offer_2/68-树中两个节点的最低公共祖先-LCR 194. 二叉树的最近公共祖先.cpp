#include "header.h"

// 235. 二叉搜索树的最近公共祖先
class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || !p || !q) {
      return nullptr;
    }
    int lValue = p->val < q->val ? p->val : q->val;
    int rValue = p->val < q->val ? q->val : p->val;
    while (root) {
      int curValue = root->val;
      if (curValue >= lValue && curValue <= rValue) {
        return root;
      }
      if (curValue >= lValue && curValue >= rValue) {
        root = root->left;
      } else {
        root = root->right;
      }
    }
    return root;
  }
};

// LCR 194. 二叉树的最近公共祖先
// 剑指 offer 思路：
// 1. 找到节点 p 和 q 所在的路径（利用先序遍历），得到两个链表
// 2. 求两个链表的最后一个公共节点，即两个节点 p 和 q 的最近公共祖先
class Solution {
  bool findPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path) {
    if (root == target) {
      path.push_back(root);
      return true;
    }
    if (root == nullptr) {
      return false;
    }
    path.push_back(root);
    bool found = false;
    found = findPath(root->left, target, path);
    if (found) {
      return true;
    }
    found = findPath(root->right, target, path);
    if (found) {
      return true;
    }
    path.pop_back();
    return false;
  }

  TreeNode *getLastCommon(const vector<TreeNode *> &path1, const vector<TreeNode *> &path2) {
    TreeNode *ans = nullptr;
    int m = path1.size();
    int n = path2.size();
    int i = 0;
    int j = 0;
    while (i < m && j < n && path1[i] == path2[j]) {
      ans = path1[i];
      ++i;
      ++j;
    }
    return ans;
  }

 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> path1;
    findPath(root, p, path1);

    vector<TreeNode *> path2;
    findPath(root, q, path2);

    return getLastCommon(path1, path2);
  }
};

// 存储父节点
class Solution {
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

 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    fa[root->val] = nullptr;  // 所有节点的值都是唯一的
    dfs(root);
    while (p != nullptr) {  // 从 p 自下向上向父节点遍历
      vis[p->val] = true;
      p = fa[p->val];
    }
    while (q != nullptr) {  // 从 q 自下向上向父节点遍历
      if (vis[q->val]) {
        return q;  // 之前已经遍历过，则此节点是最近公共祖先
      }
      q = fa[q->val];
    }
    return nullptr;
  }
};
