#include <iostream>
#include <vector>
#include <queue>
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
        while (!q.empty())
        {
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
        }
        return res;
    }
};

int main()
{

    return 0;
}