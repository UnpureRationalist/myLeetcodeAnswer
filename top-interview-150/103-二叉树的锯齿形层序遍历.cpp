#include "header.h"

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);
    bool reverse_flag = false;
    while (!q.empty()) {
      int size = q.size();
      result.emplace_back(vector<int>(size));
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        result.back()[i] = cur->val;
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
      if (reverse_flag) {
        reverse(result.back().begin(), result.back().end());
      }
      reverse_flag = !reverse_flag;
    }
    return result;
  }
};
