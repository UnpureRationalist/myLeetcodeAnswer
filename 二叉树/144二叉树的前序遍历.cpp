#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *p = root;
        stack<TreeNode*> s;
        while(p || !s.empty())
        {
            while(p)
            {
                res.push_back(p->val);
                s.push(p->right);
                p = p->left;
            }
            p = s.top();
            s.pop();
        }
        return res;
    }
};

int main()
{

    return 0;
}