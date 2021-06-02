#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (nums[i] + nums[j] != target)
        {
            if (nums[i] + nums[j] < target)
                ++i;
            else
                --j;
        }
        return {nums[i], nums[j]};
    }
};

int main()
{

    return 0;
}