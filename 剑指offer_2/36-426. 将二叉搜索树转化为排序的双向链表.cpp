#include "header.h"

// Definition for a Node.
class Node {
 public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

class Solution {
  pair<Node *, Node *> help(Node *root) {
    if (root == nullptr) {
      return {nullptr, nullptr};
    }
    auto left = help(root->left);
    auto right = help(root->right);
    root->left = left.second;
    root->right = right.first;
    if (left.second) {
      left.second->right = root;
    }
    if (right.first) {
      right.first->left = root;
    }
    return {left.first ? left.first : root, right.second ? right.second : root};
  }

 public:
  Node *treeToDoublyList(Node *root) {
    if (root == nullptr) {
      return nullptr;
    }
    auto res = help(root);
    if (res.first) {
      res.first->left = res.second;
    }
    if (res.second) {
      res.second->right = res.first;
    }
    return res.first;
  }
};
