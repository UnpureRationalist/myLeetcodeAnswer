#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr && targetSum == root->val)
            return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

int main()
{

    return 0;
}