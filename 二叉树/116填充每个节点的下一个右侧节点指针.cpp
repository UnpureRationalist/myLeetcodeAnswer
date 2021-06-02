#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        vector<Node *> v;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            v.push_back(temp);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        int n = v.size();
        int i = 0;
        int levelNumber = 1;
        while (i < n)
        {
            int MAX = i + levelNumber;
            while (i < MAX)
            {
                if (i + 1 < MAX)
                    v[i]->next = v[i + 1];
                else
                    v[i]->next = nullptr;
                ++i;
            }
            levelNumber += levelNumber;
        }
        return root;
    }
};

class Solution2
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        vector<Node *> v;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int number = q.size();
            for (int i = 0; i < number; ++i)
            {
                Node *temp = q.front();
                q.pop();
                if (i != number - 1)
                    temp->next = q.front();
                else
                    temp->next = nullptr;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return root;
    }
};

int main()
{

    return 0;
}