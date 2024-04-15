#include "header.h"

class Solution {
 public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    if (root == nullptr) {
      return result;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      while (n--) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
        if (n == 0) {
          result.emplace_back(cur->val);
        }
      }
    }
    return result;
  }
};
