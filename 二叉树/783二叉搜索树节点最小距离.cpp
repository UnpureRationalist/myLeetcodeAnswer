#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

class Solution
{

    vector<int> res;

    void inOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        inOrder(root);
        vector<int> diff(res.size());
        for (int i = 1; i < res.size(); ++i)
            diff[i] = res[i] - res[i - 1];
        return *min_element(diff.begin() + 1, diff.end());
    }
};

int main()
{

    return 0;
}