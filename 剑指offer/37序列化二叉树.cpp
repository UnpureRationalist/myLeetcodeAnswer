#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include "TreeNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    string res_str;

    void dfs_NLR(TreeNode *root)
    {
        if (root == NULL)
        {
            res_str += "NULL,";
            return;
        }

        else
        {
            res_str += (to_string(root->val) + ',');
            dfs_NLR(root->left);
            dfs_NLR(root->right);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        dfs_NLR(root);
        return res_str;
    }

    queue<string> Q;
    TreeNode *dfs()
    {
        string cur = Q.front();
        Q.pop();
        if (cur == "NULL")
            return NULL;
        TreeNode *root = new TreeNode(stoi(cur));
        root->left = dfs();
        root->right = dfs();
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int i = 0, j = 0;
        while (i < data.size())
        {
            if (data[i] != ',')
                i++;
            else
            {
                string tmp = data.substr(j, i - j);
                Q.push(tmp);
                i++;
                j = i;
            }
        }
        if (j != i)
        {
            string tmp = data.substr(j, i - j);
            Q.push(tmp);
        }
        return dfs();
    }
};

int main()
{

    return 0;
}