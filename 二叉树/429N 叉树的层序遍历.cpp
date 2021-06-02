#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> res(getDepth(root));
        Node *p = root;
        queue<Node *> q;
        q.push(p);
        queue<int> height;
        height.push(0);
        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            int h = height.front();
            height.pop();
            res[h].push_back(temp->val);
            for(auto &v : temp->children)
            {
                if(v != nullptr)
                {
                    q.push(v);
                    height.push(h+1);
                }
            }
        }
        return res;
    }

    int getDepth(Node *root)
    {
        if(root == nullptr)
            return 0;
        int h = 0;
        for(auto &v : root->children)
        {
            h = max(h, getDepth(v));
        }
        return h + 1;
    }
};

int main()
{

    return 0;
}