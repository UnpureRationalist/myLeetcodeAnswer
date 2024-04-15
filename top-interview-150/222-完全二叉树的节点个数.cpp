#include "header.h"

class Solution {
 public:
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int level = 0;
    TreeNode *node = root;
    while (node->left != nullptr) { // 层数从 0 开始编号
      level++;
      node = node->left;
    }
    int low = 1 << level, high = (1 << (level + 1)) - 1;
    while (low < high) {
      int mid = (high - low + 1) / 2 + low;
      if (exists(root, level, mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }

  bool exists(TreeNode *root, int level, int k) {
    int bits = 1 << (level - 1);
    TreeNode *node = root;
    while (node != nullptr && bits > 0) {
      if (!(bits & k)) {
        node = node->left;
      } else {
        node = node->right;
      }
      bits >>= 1;
    }
    return node != nullptr;
  }
};
