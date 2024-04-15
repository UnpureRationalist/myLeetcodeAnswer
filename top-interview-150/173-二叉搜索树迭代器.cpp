#include "header.h"

class BSTIterator {
 private:
  TreeNode *cur;
  stack<TreeNode *> stk;

 public:
  BSTIterator(TreeNode *root) : cur(root) {}

  int next() {
    while (cur != nullptr) {
      stk.push(cur);
      cur = cur->left;
    }
    cur = stk.top();
    stk.pop();
    int ret = cur->val;
    cur = cur->right;
    return ret;
  }

  bool hasNext() { return cur != nullptr || !stk.empty(); }
};
