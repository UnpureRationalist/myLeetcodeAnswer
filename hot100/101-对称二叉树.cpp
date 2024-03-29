#include <queue>
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
  bool equal(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }

    if (!(left && right)) {
      return false;
    }
    if (left->val != right->val) {
      return false;
    }
    return equal(left->right, right->left) && equal(left->left, right->right);
  }

 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return equal(root->left, root->right);
  }
};

class Solution2 {
 public:
  bool check(TreeNode *u, TreeNode *v) {
    queue<TreeNode *> q;
    q.push(u);
    q.push(v);
    while (!q.empty()) {
      u = q.front();
      q.pop();
      v = q.front();
      q.pop();
      if (!u && !v) continue;
      if ((!u || !v) || (u->val != v->val)) return false;

      q.push(u->left);
      q.push(v->right);

      q.push(u->right);
      q.push(v->left);
    }
    return true;
  }

  bool isSymmetric(TreeNode *root) { return check(root, root); }
};