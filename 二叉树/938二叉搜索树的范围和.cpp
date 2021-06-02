#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
    bool small = false;
    int sum = 0;

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return 0;
        rangeSumBST(root->left, low, high);
        if (!small && root->val >= low)
            small = true;
        if (root->val > high)
            return sum;
        if (small)
            sum += root->val;
        rangeSumBST(root->right, low, high);
        return sum;
    }
};

int main()
{

    return 0;
}