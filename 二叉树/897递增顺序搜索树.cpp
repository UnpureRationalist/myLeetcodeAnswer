#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
    TreeNode *getRightest(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        while (root->right)
            root = root->right;
        return root;
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == nullptr || root->left == nullptr && root->right == nullptr)
            return root;
        TreeNode *lchild = increasingBST(root->left);
        TreeNode *rchild = increasingBST(root->right);
        TreeNode *l_right = getRightest(lchild);
        if (l_right != nullptr)
            l_right->right = root;
        root->left = nullptr;
        root->right = rchild;
        return lchild == nullptr ? root : lchild;
    }
};

int main()
{

    return 0;
}