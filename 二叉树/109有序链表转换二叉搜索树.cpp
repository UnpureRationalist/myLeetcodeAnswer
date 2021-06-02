#include <iostream>
#include <vector>
#include "TreeNode.h"
#include "ListNode.h"
using namespace std;

class Solution
{
    TreeNode *solve(vector<int> &nums, int s, int e)
    {
        if (e < s)
            return nullptr;
        if (s == e)
        {
            return new TreeNode(nums[s]);
        }
        int mid = s + (e - s) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(nums, s, mid - 1);
        root->right = solve(nums, mid + 1, e);
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return solve(nums, 0, nums.size() - 1);
    }
};

int main()
{

    return 0;
}