#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    bool contain(TreeNode *root, int elem)
    {
        if(root == nullptr)
            return false;
        if(root->val == elem)
            return true;
        return contain(root->left, elem) || contain(root->right, elem);
    }
    
    ListNode * getRes(TreeNode *root, int elem)
    {
        if(root == nullptr)
            return nullptr;
        if(root->val == elem)
        {
            ListNode *p = new ListNode(elem);
            return p;
        }
        ListNode *head = new ListNode(root->val);
        bool left = contain(root->left, elem);
        bool right = contain(root->right, elem);
        if(left)
        {
            head->next = getRes(root->left, elem);
        }
        else
        {
            head->next = getRes(root->right, elem);
        }
        return head;
    }

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 你需要返回m个指针，第i个指针指向一条链，表示第i个问题的答案
     * @param root TreeNode类 指向链表树的根
     * @param b int整型vector 表示每个问题是什么
     * @return ListNode类vector
     */
    vector<ListNode *> solve(TreeNode *root, vector<int> &b)
    {
        // write code here
        int n = b.size();
        vector<ListNode *> res(n, nullptr);
        for(int i = 0; i < n; ++i)
        {
            res[i] = getRes(root, b[i]);
        }
        return res;
    }
};

int main()
{

    return 0;
}