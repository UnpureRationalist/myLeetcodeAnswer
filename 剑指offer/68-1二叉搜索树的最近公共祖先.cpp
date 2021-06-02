#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p == q)
            return p;
        if (root == nullptr)
            return root;
        if (p->val > q->val)
        {
            TreeNode *temp = p;
            p = q;
            q = temp;
        }
        // 此时 p->val 一定小于 q->val  因此可简化 while 循环条件
        while (root->val > q->val || root->val < p->val)
        {
            if (root->val < p->val)
                root = root->right;
            else if (root->val > p->val)
                root = root->left;
        }
        return root;
    }
};

class Solution2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p == q)
            return p;
        if (root == nullptr)
            return root;
        int small = p->val;
        int big = q->val;
        if (small > big)
        {
            int temp = small;
            small = big;
            big = temp;
        }
        // 此时 small 一定小于 big  因此可简化 while 循环条件
        while (root->val > big || root->val < small)
        {
            if (root->val < small)
                root = root->right;
            else if (root->val > big)
                root = root->left;
        }
        return root;
    }
};

int main()
{
    Solution2 s;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    cout << s.lowestCommonAncestor(root, root, root->left)->val << endl;
    return 0;
}