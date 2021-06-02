#include <iostream>
#include <cmath>
#include "TreeNode.h"
using namespace std;

class Solution
{
    int getDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if(root == nullptr)
            return true;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        if(abs(l - r) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main()
{

    return 0;
}