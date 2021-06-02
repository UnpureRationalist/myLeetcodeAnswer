#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
    bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max)
    {
        if(!root)
            return true;
        if(min != nullptr && root->val <= min->val)
            return false;
        if(max != nullptr && root->val >= max->val)
            return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, nullptr, nullptr);
    }
};

int main()
{

    return 0;
}