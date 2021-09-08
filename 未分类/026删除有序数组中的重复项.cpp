#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        auto n = nums.size();
        int low = 0;
        int high = 1;
        int val = nums[low];
        while(high < n)
        {
            while(nums[high - 1] == nums[high])
            {
                ++high;
            }
            nums[low++] = nums[high - 1];
            high++;
        }
        return low;
    }
};

int main()
{

    return 0;
}