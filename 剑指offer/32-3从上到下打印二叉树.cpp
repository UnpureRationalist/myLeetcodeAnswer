#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            ++level;
            auto size = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < size; ++i)
            {
                auto ptr = q.front();
                q.pop();
                res.back().push_back(ptr->val);
                if (ptr->left)
                    q.push(ptr->left);
                if (ptr->right)
                    q.push(ptr->right);
            }
            if (level % 2 == 0)
                reverse(res.back().begin(), res.back().end());
        }
        return res;
    }
};

int main()
{

    return 0;
}