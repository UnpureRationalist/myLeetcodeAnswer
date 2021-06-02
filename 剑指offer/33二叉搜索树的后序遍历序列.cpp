#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool help(vector<int> &postorder, int s, int e)
    {
        if (s >= e)
            return true;
        int maxElem = postorder[e];
        int i = s;
        for (; i < e && postorder[i] < maxElem; ++i)
            ;
        if (i < e)
        {
            for (int j = i; j < e; ++j)
            {
                if (postorder[j] < maxElem)
                    return false;
            }
        }
        return help(postorder, s, i - 1) && help(postorder, i, e - 1);
    }

public:
    bool verifyPostorder(vector<int> &postorder)
    {
        if (postorder.size() <= 1)
            return true;
        return help(postorder, 0, postorder.size() - 1);
    }
};

int main()
{
    vector<int> v = {4, 8, 6, 12, 16, 14, 10};
    Solution s;
    cout << s.verifyPostorder(v) << endl;
    return 0;
}