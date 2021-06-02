#include <iostream>
#include <cmath>
#include "TreeNode.h"
using namespace std;

class Solution
{
    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if(root == nullptr)
            return true;
        int leftHeight = getDepth(root->left);
        int rightHeight = getDepth(root->right);
        return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

int main()
{

    return 0;
}