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
 public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    queue<TreeNode *> q;
    if (root != nullptr) {
      q.push(root);
    }
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->left) {
          q.push(temp->left);
        }
        if (temp->right) {
          q.push(temp->right);
        }
        if (size == 0) {
          result.emplace_back(temp->val);
        }
      }
    }
    return result;
  }
};