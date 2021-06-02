#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int count = 0;
    int n;
    vector<int> select;
    void solve(int k, vector<vector<int>> &res, vector<int> &nums)
    {
        if(k == n)
        {
            for(int i = 0; i < n; ++i)
            {
                if(select[i] == 2)
                    res[count].push_back(nums[i]);
            }
            ++count;
            return ;
        }
        for(int i = 1; i <= 2; ++i)
        {
            select[k] = i;
            solve(k + 1, res, nums);
            select[k] = 0;
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        this->n = nums.size();
        select.resize(n);
        vector<vector<int>> res(1 << n);
        solve(0, res, nums);
        return res;
    }
};

int main()
{

    return 0;
}