#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j)
        {
            while(i < j && nums[j]%2 == 0)
                --j;
            while(i < j && nums[i]%2 == 1)
                ++i;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};

int main()
{

    return 0;
}