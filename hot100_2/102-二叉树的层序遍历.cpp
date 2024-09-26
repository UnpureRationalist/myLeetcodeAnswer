#include "TreeNode.h"

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root != nullptr) {
      queue<TreeNode *> q;
      q.emplace(root);

      while (!q.empty()) {
        int size = q.size();
        result.emplace_back();
        result.back().reserve(size);
        while (size--) {
          TreeNode *cur = q.front();
          q.pop();
          result.back().push_back(cur->val);
          if (cur->left) {
            q.emplace(cur->left);
          }
          if (cur->right) {
            q.emplace(cur->right);
          }
        }
      }
    }
    return result;
  }
};
