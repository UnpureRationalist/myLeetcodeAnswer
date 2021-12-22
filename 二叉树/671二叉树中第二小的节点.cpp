#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "TreeNode.hpp"
using namespace std;

class Solution
{
    vector<int> v;

    void helper(TreeNode *root)
    {
        if (!root)
            return;
        v.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        helper(root);
        sort(v.begin(), v.end());
        int n = v.size();
        if (n <= 1)
            return -1;
        int i = 1;
        while (i < n && v[i] == v[0])
            ++i;
        if (i == n)
            return -1;
        return v[i];
    }
};

class Solution
{
public:
    int findSecondMinimumValue(TreeNode *root)
    {
        int ans = -1;
        int rootvalue = root->val;

        function<void(TreeNode *)> dfs = [&](TreeNode *node)
        {
            if (!node)
            {
                return;
            }
            if (ans != -1 && node->val >= ans)
            {
                return;
            }
            if (node->val > rootvalue)
            {
                ans = node->val;
            }
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        return ans;
    }
};

int main()
{

    return 0;
}