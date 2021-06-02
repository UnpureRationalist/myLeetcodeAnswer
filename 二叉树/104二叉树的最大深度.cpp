#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }

    int getDepth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};

int main()
{

    return 0;
}