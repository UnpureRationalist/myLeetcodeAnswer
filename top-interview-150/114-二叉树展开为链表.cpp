#include "header.h"

class Solution {
 public:
  void flatten(TreeNode *root) {
    TreeNode *curr = root;
    while (curr) {
      if (curr->left) {
        auto next = curr->left;
        auto predecessor = next;
        while (predecessor->right != nullptr) {
          predecessor = predecessor->right;
        }
        predecessor->right = curr->right;
        curr->left = nullptr;
        curr->right = next;
      }
      curr = curr->right;
    }
  }
};
