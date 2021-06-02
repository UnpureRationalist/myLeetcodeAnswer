#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        TreeNode *p = root;
        if (p == nullptr)
            return 0;
        queue<TreeNode *> q;
        queue<int> height;
        vector<int> v;
        q.push(p);
        height.push(1);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            int h = height.front();
            q.pop();
            height.pop();
            if (temp->left)
            {
                q.push(temp->left);
                height.push(h + 1);
            }
            if (temp->right)
            {
                q.push(temp->right);
                height.push(h + 1);
            }
            if (!temp->left && !temp->right)
            {
                // v.push_back(h);
                return h;
            }
        }
        // return *min_element(v.begin(), v.end());
        return 0;
    }
};

class Solution2
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left != nullptr)
        {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr)
        {
            min_depth = min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};

int main()
{

    return 0;
}