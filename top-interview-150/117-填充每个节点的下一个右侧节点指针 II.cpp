
// Definition for a Node.
class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  void handle(Node *&last, Node *cur, Node *&next_level_start) {
    if (last) {
      last->next = cur;
    }
    last = cur;
    if (!next_level_start) {
      next_level_start = cur;
    }
  }

 public:
  Node *connect(Node *root) {
    if (root == nullptr) {
      return nullptr;
    }
    Node *start = root;
    while (start) {
      Node *last = nullptr;
      Node *next_level_start = nullptr;
      for (Node *cur = start; cur; cur = cur->next) {
        if (cur->left) {
          handle(last, cur->left, next_level_start);
        }
        if (cur->right) {
          handle(last, cur->right, next_level_start);
        }
      }
      start = next_level_start;
    }
    return root;
  }
};
