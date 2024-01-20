#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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
  TreeNode *help(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    root->left = nullptr;
    root->right = help(left);
    TreeNode *temp = root;
    while (temp->right) {
      temp = temp->right;
    }
    temp->right = help(right);
    return root;
  }

 public:
  void flatten(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    help(root);
  }
};

class Solution {
 public:
  void flatten(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (root || !s.empty()) {
      if (root) {
        if (root->right) s.push(root->right);
        if (root->left) {
          p->right = root->left;
          p = root->left;
        }
        auto temp = root->left;
        root->left = nullptr;
        root = temp;
      } else {
        root = s.top();
        s.pop();
        p->right = root;
        p = root;
      }
    }
  }
};
