#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        auto n = nums.size();
        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp{{0, -1}};
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
            else
            {
                res = max(res, i - mp[sum]);
            }
        }
        return res;
    }
};

int main() { return 0; }