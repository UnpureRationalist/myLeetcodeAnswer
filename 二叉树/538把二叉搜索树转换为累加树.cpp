#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution
{
    vector<int> trans;

    void inOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inOrder(root->left);
        trans.push_back(root->val);
        inOrder(root->right);
    }

    void inOrder(TreeNode *root, int &i)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, i);
        root->val = trans[i];
        ++i;
        inOrder(root->right, i);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        inOrder(root);
        int n = trans.size();
        for (int i = n - 2; i >= 0; --i)
            trans[i] = trans[i] + trans[i + 1];

        int index = 0;
        inOrder(root, index);
        return root;
    }
};

class Solution2
{
public:
    int sum = 0;

    TreeNode *convertBST(TreeNode *root)
    {
        if (root != nullptr)
        {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};

int main()
{

    return 0;
}