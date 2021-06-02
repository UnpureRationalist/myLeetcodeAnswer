#include <iostream>
#include <vector>
#include <algorithm>
#include "TreeNode.h"
using namespace std;
// 由 中序 和 后序 遍历构造二叉树   ( 假设树中没有重复的元素 )
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        TreeNode *root = nullptr;
        if (inorder.empty())
            return nullptr;
        root = buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe)
    {
        if (is >= ie || ps >= pe)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[pe - 1]); // 后序遍历最后一个为 根节点

        vector<int>::iterator pos = find(inorder.begin() + is, inorder.begin() + ie, postorder[pe - 1]);

        int leftTreeSize = pos - inorder.begin() - is; // 左子树大小

        // 递归构造  注意下标的计算
        root->left = buildTree(inorder, is, is + leftTreeSize, postorder, ps, ps + leftTreeSize);
        root->right = buildTree(inorder, is + leftTreeSize + 1, ie, postorder, ps + leftTreeSize, pe - 1);

        return root;
    }
};

int main()
{

    return 0;
}