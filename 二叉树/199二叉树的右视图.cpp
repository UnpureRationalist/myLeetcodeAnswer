#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        vector<int> level;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            level.clear();
            auto size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            res.push_back(level.back());
        }
        return res;
    }
};

int main()
{

    return 0;
}