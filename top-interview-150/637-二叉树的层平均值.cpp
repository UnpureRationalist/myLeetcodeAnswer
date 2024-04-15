#include "header.h"

class Solution {
 public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> result;
    if (!root) {
      return result;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      double sum = 0;
      for (int i = 0; i < n; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
        sum += cur->val;
      }
      result.emplace_back(sum / n);
    }
    return result;
  }
};
