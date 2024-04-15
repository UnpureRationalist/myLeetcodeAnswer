#include "header.h"

class Solution {
  TreeNode *build(vector<int> &nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    int mid = (start + end) / 2;
    int value = nums[mid];
    TreeNode *root = new TreeNode(value);
    if (start == end) {
      return root;
    }
    root->left = build(nums, start, mid - 1);
    root->right = build(nums, mid + 1, end);
    return root;
  }

 public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int n = nums.size();
    return build(nums, 0, n - 1);
  }
};
