#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = i + 1;
        return buildTree(v);
    }

    vector<TreeNode *> buildTree(vector<int> node) // 生成 node 数组构成的BST,node必须为升序排序
    {
        int i = node.size();
        vector<TreeNode *> res;
        if (node.empty() || i == 0)
            return res;
        if (i == 1)
        {
            TreeNode *root = new TreeNode(node[0]);
            res.push_back(root);
        }
        else if (i == 2)
        {
            /*
                1
                 \
                  2
            */
            TreeNode *root = new TreeNode(node[0]);
            root->right = new TreeNode(node[1]);
            res.push_back(root);
            /*
                    2
                  /
                1
            */
            root = new TreeNode(node[1]);
            root->left = new TreeNode(node[0]);
            res.push_back(root);
        }
        else if (i >= 3) // i >= 3
        {
            for (int j = 0; j < i; ++j)
            {
                TreeNode *root;
                vector<int> left, right;

                for (int k = 0; k < j; ++k)
                    left.push_back(node[k]);

                for (int k = j + 1; k < i; ++k)
                    right.push_back(node[k]);

                vector<TreeNode *> l = buildTree(left);
                vector<TreeNode *> r = buildTree(right);

                if (l.size() == 0 && r.size() != 0)
                {
                    for (int k = 0; k < r.size(); ++k)
                    {
                        root = new TreeNode(node[j]);
                        root->left = nullptr;
                        root->right = r[k];
                        res.push_back(root);
                    }
                }
                else if (l.size() != 0 && r.size() == 0)
                {
                    for (int k = 0; k < l.size(); ++k)
                    {
                        root = new TreeNode(node[j]);
                        root->right = nullptr;
                        root->left = l[k];
                        res.push_back(root);
                    }
                }
                else
                {
                    for (int k = 0; k < l.size(); ++k)
                    {
                        for (int m = 0; m < r.size(); ++m)
                        {
                            root = new TreeNode(node[j]);
                            root->left = l[k];
                            root->right = r[m];
                            res.push_back(root);
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}