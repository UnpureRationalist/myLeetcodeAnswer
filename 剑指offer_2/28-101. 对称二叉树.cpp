#include "header.h"

class Solution {
  bool isSymmetricInternal(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) {
      return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
      return false;
    }
    if (root1->val != root2->val) {
      return false;
    }
    return isSymmetricInternal(root1->left, root2->right) && isSymmetricInternal(root1->right, root2->left);
  }

 public:
  bool isSymmetric(TreeNode *root) { return isSymmetricInternal(root, root); }
};

// 迭代
class Solution {
  bool levelIsSymmetric(const vector<TreeNode *> &level) {
    int i = 0;
    int j = level.size() - 1;
    while (i < j) {
      if (level[i] == nullptr && level[j] == nullptr) {
        ++i;
        --j;
        continue;
      }
      if (level[i] == nullptr || level[j] == nullptr) {
        return false;
      }
      if (level[i]->val != level[j]->val) {
        return false;
      }
      ++i;
      --j;
    }
    return true;
  }

 public:
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    queue<TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
      int q_size = q.size();
      vector<TreeNode *> level;
      while (q_size--) {
        TreeNode *cur = q.front();
        q.pop();
        level.push_back(cur);
        if (cur) {
          q.emplace(cur->left);
          q.emplace(cur->right);
        }
      }
      bool isSym = levelIsSymmetric(level);
      if (!isSym) {
        return false;
      }
    }
    return true;
  }
};