#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int target = nums[i] + nums[j] - 1;
                auto start = nums.begin() + j + 1;
                auto iter = upper_bound(start, nums.end(), target);
                res += iter - start;
            }
        }
        return res;
    }
};

class Solution2
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int k = i;
            for (int j = i + 1; j < n; ++j)
            {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j])
                {
                    ++k;
                }
                ans += max(k - j, 0);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}