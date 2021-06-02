#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p || !s.empty())
        {
            if (p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                TreeNode *temp = s.top();
                s.pop();
                res.push_back(temp->val);
                p = temp->right;
            }
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p || !s.empty())
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }
            TreeNode *temp = s.top();
            s.pop();
            res.push_back(temp->val);
            p = temp->right;
        }
        return res;
    }
};

int main()
{

    return 0;
}