#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        TreeNode *rt = new TreeNode(root->val);

        rt->right = mirrorTree(root->left);
        rt->left = mirrorTree(root->right);
        return rt;
    }

    bool isSameTree(TreeNode *root, TreeNode *mirror)
    {
        if (root == nullptr && mirror == nullptr)
            return true;
        if (root == nullptr && mirror != nullptr || root != nullptr && mirror == nullptr)
            return false;
        if (root->val != mirror->val)
            return false;
        return isSameTree(root->left, mirror->left) && isSameTree(root->right, mirror->right);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *mirror = mirrorTree(root);
        return isSameTree(root, mirror);
    }
};

int main()
{

    return 0;
}