#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    map<Node *, Node *> mp;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        Node *res = new Node(node->val);
        mp[node] = res;
        for (auto nd : node->neighbors)
        {
            if (mp.find(nd) == mp.end())
            {
                Node *chi = cloneGraph(nd);
                if (chi)
                {
                    res->neighbors.push_back(chi);
                }
            }
            else
            {
                res->neighbors.push_back(mp[nd]);
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}