#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        vector<int> res;
        preOrderTraverse(root, res);
        TreeNode *p = root;
        bool flag = true;
        for (int i = 1; i < res.size(); ++i)
        {
            p->left = nullptr;
            p->right = new TreeNode(res[i]);
            p = p->right;
        }
    }

    void preOrderTraverse(TreeNode *root, vector<int> &res)
    {
        if (root)
        {
            res.push_back(root->val);
            preOrderTraverse(root->left, res);
            preOrderTraverse(root->right, res);
        }
    }
};

class Solution2
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        auto stk = stack<TreeNode *>();
        stk.push(root);
        TreeNode *prev = nullptr;
        while (!stk.empty())
        {
            TreeNode *curr = stk.top();
            stk.pop();
            if (prev != nullptr)
            {
                prev->left = nullptr;
                prev->right = curr;
            }
            TreeNode *left = curr->left, *right = curr->right;
            if (right != nullptr)
            {
                stk.push(right);
            }
            if (left != nullptr)
            {
                stk.push(left);
            }
            prev = curr;
        }
    }
};

class Solution3
{
public:
    void flatten(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *p = root;
        while(root || !s.empty())
        {
            if(root)
            {
                if(root->right)
                    s.push(root->right);
                if(root->left)
                {
                    p->right = root->left;
                    p = root->left;
                }
                auto temp = root->left;
                root->left = nullptr;
                root = temp;
            }
            else
            {
                root = s.top();
                s.pop();
                p->right = root;
                p = root;
            }
        }
    }
};

int main()
{

    return 0;
}