#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
 public:
  void flatten(TreeNode *root) {
    TreeNode *curr = root;
    while (curr) {
      if (curr->left) {
        TreeNode *next = curr->left;
        TreeNode *predecessor = next;
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
