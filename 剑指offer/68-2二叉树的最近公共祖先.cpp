#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
    TreeNode *res = nullptr;

    bool postTraverse(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr)
            return false;
        bool lchild = postTraverse(root->left, p, q);
        bool rchild = postTraverse(root->right, p, q);
        if( (lchild && rchild) || (root == p && (lchild || rchild)) || (root == q && (lchild || rchild)) )
            res = root;
        return lchild || rchild || root == p || root == q;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        postTraverse(root, p, q);
        return res;
    }
};

int main()
{

    return 0;
}