struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;
  TreeNode() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *par) : val(x), left(left), right(right), parent(par) {}
};

class Solution {
 public:
  TreeNode *nextTreeNode(TreeNode *node) {
    if (node == nullptr) {
      return nullptr;
    }
    TreeNode *pNext = nullptr;

    if (node->right) {  // 右子树非空
      TreeNode *rchild = node->right;
      while (rchild->left) {
        rchild = rchild->left;  // 右子树的最左子节点就是后继节点
      }
      pNext = rchild;
    } else if (node->parent) {  // 父节点非空
      TreeNode *pCurrent = node;
      TreeNode *pParent = node->parent;
      while (pParent && pCurrent == pParent->right) {
        pCurrent = pParent;
        pParent = pParent->parent;
      }
      pNext = pParent;
    }
    return pNext;
  }
};
