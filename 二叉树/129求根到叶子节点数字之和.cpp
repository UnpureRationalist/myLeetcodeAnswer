#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int sum = 0;
        cal(root, 0, sum);
        return sum;
    }

    void cal(TreeNode *root, int n, int& sum)
    {
        if(!root)
            return;
        if(root->left && !root->right)      // 左子树非空 右子树空
        {
            cal(root->left, n*10 + root->val, sum);
        }
        else if(!root->left && root->right) // 左子树空 右子树非空
        {
            cal(root->right, n*10 + root->val, sum);
        }
        else if(root->left && root->right)  // 左右子树都非空
        {
            cal(root->left, n*10 + root->val, sum);
            cal(root->right, n*10 + root->val, sum);
        }
        else    // 叶子节点
        {
            n = 10*n + root->val;
            sum += n;
            return;
        }
    }
};

int main()
{

    return 0;
}