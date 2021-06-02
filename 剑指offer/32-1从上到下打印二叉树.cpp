#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return vector<int>();
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            res.push_back(temp->val);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}