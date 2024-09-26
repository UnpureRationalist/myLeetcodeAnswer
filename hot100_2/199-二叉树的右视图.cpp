#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
 public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    queue<TreeNode *> q;
    if (root) {
      q.emplace(root);
    }
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = q.front();
        if (i == size - 1) {
          result.push_back(cur->val);
        }
        q.pop();
        if (cur->left) {
          q.emplace(cur->left);
        }
        if (cur->right) {
          q.emplace(cur->right);
        }
      }
    }
    return result;
  }
};
