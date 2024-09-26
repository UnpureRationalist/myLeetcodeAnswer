#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution {
  void inorderTraversal(TreeNode *root, vector<int> &result) {
    if (root == nullptr) {
      return;
    }
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
  }

 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    inorderTraversal(root, result);
    return result;
  }
};
