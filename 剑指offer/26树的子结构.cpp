#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution
{
    bool isContain(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr)
            return true;
        if (A == nullptr || A->val != B->val)
            return false;
        return isContain(A->left, B->left) && isContain(A->right, B->right);
    }

public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr || A == nullptr)
            return false;
        return isContain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

int main()
{

    return 0;
}