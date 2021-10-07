#include <iostream>
#include <vector>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

class Solution
{
    vector<int> preSum;
    int count = 0;

    void dfs(TreeNode *root, int target)
    {
        if (root == nullptr)
        {
            return;
        }

        preSum.push_back(root->val + preSum.back());

        int purpose = preSum.back() - target;
        count += count_if(preSum.begin(), preSum.end() - 1, [purpose](int val) -> bool
                          { return val == purpose; });

        dfs(root->left, target);
        dfs(root->right, target);

        preSum.pop_back();
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        preSum.push_back(0);
        dfs(root, targetSum);
        return count;
    }
};