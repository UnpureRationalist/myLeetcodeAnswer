#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        vector<long long> sums;
        sums.push_back(0);
        for (auto elem : nums)
        {
            sums.push_back(sums.back() + elem);
        }
        unordered_map<long long, int> mp;
        auto n = sums.size();
        for (int i = 0; i < n; ++i)
        {
            if (mp.find(sums[i] % k) == mp.end())
            {
                mp.insert({sums[i] % k, i});
            }
            else
            {
                if ((i - mp[sums[i] % k]) >= 2)
                    return true;
            }
        }
        return false;
    }
};

class Solution2
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        auto n = nums.size();
        if (n < 2)
        {
            return false;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < n; i++)
        {
            remainder = (remainder + nums[i]) % k;
            if (mp.find(remainder) == mp.end())
            {
                mp.insert({remainder, i});
            }
            else
            {
                if ((i - mp[remainder]) >= 2)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}