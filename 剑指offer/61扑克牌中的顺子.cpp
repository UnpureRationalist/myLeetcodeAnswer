#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 1;
        for (; i < n; ++i)
            if (nums[i - 1] != 0 && nums[i] != nums[i - 1] + 1)
                break;

        if (i == n)
            return true;
        else
        {
            int countZero = 0;
            for (int i = 0; i < n; ++i)
                if (nums[i] == 0)
                    ++countZero;
            if (countZero == 0)
                return false;

            int notZeroIndex = 0;
            for (int i = 0; i < n; ++i)
                if (nums[i] != 0)
                {
                    notZeroIndex = i;
                    break;
                }
            nums[0] = nums[i - 1] + 1;
            return isStraight(nums);
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    cout << s.isStraight(nums) << endl;
    return 0;
}