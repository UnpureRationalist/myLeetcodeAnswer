#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ancestor = root;
        while (true)
        {
            if (p->val < ancestor->val && q->val < ancestor->val)
            {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val)
            {
                ancestor = ancestor->right;
            }
            else
            {
                break;
            }
        }
        return ancestor;
    }
};

int main()
{

    return 0;
}