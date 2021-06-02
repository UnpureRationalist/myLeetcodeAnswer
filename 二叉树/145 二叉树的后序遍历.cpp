#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *p = root;
        stack<TreeNode *> s;
        stack<bool> flagStack;
        while (p || !s.empty())
        {
            if (p)
            {
                s.push(p);
                flagStack.push(1);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
                bool flag = flagStack.top();
                flagStack.pop();
                if (flag) //第 1 次出现在栈顶
                {
                    s.push(p);
                    flagStack.push(0);
                    p = p->right;
                }
                else
                {
                    res.push_back(p->val);
                    p = nullptr;
                }
            }
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev)
            {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            }
            else
            {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}