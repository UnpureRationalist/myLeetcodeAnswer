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
  int times{0};
  int value;
  void kth(TreeNode *root, int k) {
    if (times >= k) {
      return;
    }
    if (root == nullptr) {
      return;
    }
    kth(root->left, k);
    ++times;
    if (times == k) {
      value = root->val;
    }
    kth(root->right, k);
  }

 public:
  int kthSmallest(TreeNode *root, int k) {
    times = 0;
    kth(root, k);
    return value;
  }
};
