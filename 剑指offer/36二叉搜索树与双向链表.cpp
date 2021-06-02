#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

/*
    特别地，我们希望可以就地完成转换操作。
    当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。
    还需要返回链表中的第一个节点的指针。
*/
class Solution
{
    typedef pair<Node *, Node *> Type;
    pair<Node *, Node *> help(Node *root)
    {
        if (root == nullptr)
            return Type(root, root);
        Type left = help(root->left);
        Type right = help(root->right);
        root->left = left.second;
        root->right = right.first;
        if (left.second)
            left.second->right = root;
        if (right.first)
            right.first->left = root;
        return Type(left.first != nullptr ? left.first : root, right.second != nullptr ? right.second : root);
    }

public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        Type res = help(root);
        if (res.first)
            res.first->left = res.second;
        if (res.second)
            res.second->right = res.first;
        return res.first;
    }
};

int main()
{

    return 0;
}