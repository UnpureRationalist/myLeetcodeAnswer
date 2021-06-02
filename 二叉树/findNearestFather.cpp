#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode *findNearestFather(TreeNode *root, TreeNode *child1, TreeNode *child2)
{
    if (child1 == child2)
        return child1;
    if (root == nullptr)
        return root;

    queue<TreeNode *> q1;
    queue<int> q2;
    vector<int> parent;
    vector<int> heightRecord;
    vector<TreeNode *> res;
    queue<int> height;

    int count = 0;

    q1.push(root);
    q2.push(count);
    parent.push_back(-1);
    height.push(0);
    heightRecord.push_back(0);
    res.push_back(root);

    int findCount = 0;
    vector<int> child;

    while (!q1.empty())
    {
        TreeNode *temp = q1.front();
        q1.pop();

        int parentIndex = q2.front();
        q2.pop();

        if (temp == child1)
            child.push_back(parentIndex);
        if (temp == child2)
            child.push_back(parentIndex);

        int h = height.front();
        height.pop();

        if (temp->left)
        {
            count++;
            parent.push_back(parentIndex);
            heightRecord.push_back(h + 1);
            height.push(h + 1);
            q1.push(temp->left);
            q2.push(count);
            res.push_back(temp->left);
        }
        if (temp->right)
        {
            count++;
            parent.push_back(parentIndex);
            heightRecord.push_back(h + 1);
            height.push(h + 1);
            q1.push(temp->right);
            q2.push(count);
            res.push_back(temp->right);
        }
        if (child.size() == 2)
            break;
    }

    int i = child[0], j = child[1];

    while (i != j && parent[i] != parent[j])
    {
        if (heightRecord[i] > heightRecord[j])
        {
            i = parent[i];
        }
        else if (heightRecord[i] < heightRecord[j])
        {
            j = parent[j];
        }
        else
        {
            i = parent[i];
            j = parent[j];
        }
    }
    return i == j ? res[i] : res[parent[i]];
}

class Solution
{
    TreeNode *ans;

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == nullptr)
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);     // 后序遍历
        //  左右子树都已找到       本节点就是p            本节点就是 q             另一个也已经找到
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson)))
        {
            ans = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout << findNearestFather(root, root, root->left)->val << endl;
    return 0;
}