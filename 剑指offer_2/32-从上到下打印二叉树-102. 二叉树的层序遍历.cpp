#include "header.h"

// Leetcode 102. 二叉树的层序遍历
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root) {
      return ans;
    }
    queue<TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
      int q_size = q.size();
      ans.push_back(vector<int>(q_size));
      for (int i = 0; i < q_size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        ans.back()[i] = cur->val;
        if (cur->left) {
          q.emplace(cur->left);
        }
        if (cur->right) {
          q.emplace(cur->right);
        }
      }
    }
    return ans;
  }
};

// 自底向上层序遍历 107. 二叉树的层序遍历 II
class Solution {
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root) {
      return ans;
    }
    queue<TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
      int q_size = q.size();
      ans.push_back(vector<int>(q_size));
      for (int i = 0; i < q_size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        ans.back()[i] = cur->val;
        if (cur->left) {
          q.emplace(cur->left);
        }
        if (cur->right) {
          q.emplace(cur->right);
        }
      }
    }
    return ans;
  }

 public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    auto ans = levelOrder(root);
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};

// 103. 二叉树的锯齿形层序遍历
class Solution {
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root) {
      return ans;
    }
    queue<TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
      int q_size = q.size();
      ans.push_back(vector<int>(q_size));
      for (int i = 0; i < q_size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        ans.back()[i] = cur->val;
        if (cur->left) {
          q.emplace(cur->left);
        }
        if (cur->right) {
          q.emplace(cur->right);
        }
      }
    }
    return ans;
  }

 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    auto ans = levelOrder(root);
    int n = ans.size();
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        std::reverse(ans[i].begin(), ans[i].end());
      }
    }
    return ans;
  }
};