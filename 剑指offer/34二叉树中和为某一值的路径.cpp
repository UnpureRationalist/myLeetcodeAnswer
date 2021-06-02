#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution
{
    void calculate(TreeNode *root, int target, vector<int> &already, vector<vector<int>> &res)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr && target - root->val == 0)
        {
            already.push_back(root->val);
            res.push_back(already);
            already.pop_back();
            return;
        }
        already.push_back(root->val);
        calculate(root->left, target - root->val, already, res);
        calculate(root->right, target - root->val, already, res);
        already.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        vector<vector<int>> res;
        vector<int> path;
        calculate(root, target, path, res);
        return res;
    }
};

int main()
{

    return 0;
}