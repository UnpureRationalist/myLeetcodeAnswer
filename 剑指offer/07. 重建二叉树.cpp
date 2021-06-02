#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "TreeNode.h"
using namespace std;
// 由 前序 和 中序 遍历构造二叉树 ( 假设树中没有重复的元素 )
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = nullptr;
        if (preorder.empty())
            return root;
        root = buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return root;
    }

    // 左闭右开区间
    TreeNode *buildTree(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie)
    {
        TreeNode *root = nullptr;
        if (ps >= pe || is >= ie) // 区间为空时 递归结束
            return root;
        
        root = new TreeNode(preorder[ps]); // 构造根节点

        vector<int>::iterator pos = find(inorder.begin() + is, inorder.begin() + ie, preorder[ps]); // 查找子树的根节点在 中序 遍历中的位置

        int leftTreeSize = pos - inorder.begin() - is; // 左子树大小

        // 递归构造  注意下标的计算
        root->left = buildTree(preorder, ps + 1, ps + leftTreeSize + 1, inorder, is, leftTreeSize + is);
        root->right = buildTree(preorder, ps + leftTreeSize + 1, pe, inorder, leftTreeSize + 1 + is, ie);
        
        return root;
    }
};

int main()
{

    return 0;
}