#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};

int main()
{

    return 0;
}