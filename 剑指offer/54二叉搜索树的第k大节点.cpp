#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution
{
    void help(TreeNode *root, vector<int> &preorder)
    {
        if (root == nullptr)
            return;
        help(root->right, preorder);
        preorder.push_back(root->val);
        help(root->left, preorder);
    }

public:
    int kthLargest(TreeNode *root, int k)
    {
        vector<int> preorder;
        help(root, preorder);
        return preorder[k - 1];
    }
};

int main()
{

    return 0;
}