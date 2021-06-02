#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution2
{
public:
    int majorityElement(vector<int> &nums)
    {
        int x = 0, votes = 0;
        for (int num : nums)
        {
            if (votes == 0)
                x = num;
            votes += num == x ? 1 : -1;
        }
        return x;
    }
};

int main()
{

    return 0;
}