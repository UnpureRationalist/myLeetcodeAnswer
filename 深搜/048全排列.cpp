#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int n;
    vector<vector<int>> res;

    vector<int> num;

    vector<int> index;

    vector<int> used;

    void dfs(int i)
    {
        if (i == n)
        {
            vector<int> temp(n);
            for (int i = 0; i < n; ++i)
                temp[i] = num[index[i]];
            res.push_back(temp);
            return;
        }
        for (int j = 0; j < n; ++j)
        {
            if (!used[j])
            {
                index[i] = j;
                used[j] = true;
                dfs(i + 1);
                used[j] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();
        num = nums;
        index.assign(n, 0);
        used.assign(n, false);
        dfs(0);
        return res;
    }
};

int main()
{

    return 0;
}