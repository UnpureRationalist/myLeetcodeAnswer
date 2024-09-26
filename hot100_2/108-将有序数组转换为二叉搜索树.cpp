#include "TreeNode.h"

class Solution {
  TreeNode *buildTree(const vector<int> &nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    if (left == right) {
      TreeNode *root = new TreeNode(nums[left]);
      return root;
    }
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, left, mid - 1);
    root->right = buildTree(nums, mid + 1, right);
    return root;
  }

 public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int n = nums.size();
    return buildTree(nums, 0, n - 1);
  }
};
