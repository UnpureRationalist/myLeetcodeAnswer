#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        vector<int> hash(nums.size());
        for (auto i : nums)
        {
            hash[i]++;
            if (hash[i] == 2)
                return i;
        }
        return -1;
    }
};

class Solution2
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        int temp;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] != i)
            {
                if (nums[i] == nums[nums[i]])
                {
                    return nums[i];
                }
                temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}