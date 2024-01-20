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
  void inorderTraversal(TreeNode *root, vector<int> &result) {
    if (root == nullptr) {
      return;
    }
    inorderTraversal(root->left, result);
    result.emplace_back(root->val);
    inorderTraversal(root->right, result);
  }

 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    inorderTraversal(root, result);
    return result;
  }
};