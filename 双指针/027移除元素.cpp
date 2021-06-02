#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

class Solution2
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; ++j)
        {
            if (nums[j] != val)
            {
                nums[i++] = nums[j];
            }
        }
        nums.erase(nums.begin() + i, nums.end());
        return i;
    }
};

int main()
{

    return 0;
}