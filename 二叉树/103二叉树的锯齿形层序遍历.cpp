#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> res(getDepth(root));
        TreeNode *p = root;
        queue<TreeNode *> q;
        q.push(p);
        queue<int> height; // 记录节点所属层次
        height.push(0);
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            int h = height.front();
            height.pop();
            res[h].push_back(t->val);
            if (t->left)
            {
                q.push(t->left);
                height.push(h + 1); // 保存层次
            }
            if (t->right)
            {
                q.push(t->right);
                height.push(h + 1); // 保存层次
            }
        }
        int count = 0;
        for(auto &v : res)
        {
            if(count%2)
            {
                reverse(v.begin(), v.end());
            }
            ++count;
        }
        return res;
    }

    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};

int main()
{

    return 0;
}