#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{

    return 0;
}