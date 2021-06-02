#include <iostream>
#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution
{

    vector<vector<int>> res;
    vector<int> path;
    void solve(TreeNode *root, int left)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr && left == root->val)
        {
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        solve(root->left, left - root->val);
        solve(root->right, left - root->val);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        solve(root, targetSum);
        return res;
    }
};

class Solution2
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return;
        }
        path.emplace_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0)
        {
            ret.emplace_back(path);
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        dfs(root, sum);
        return ret;
    }
};

int main()
{

    return 0;
}