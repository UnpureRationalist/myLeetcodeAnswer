#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int, greater<int>> s(nums.begin(), nums.end());
        int count = 0;
        int maxElem, thirdElem;
        for (auto elem : s)
        {
            if (count >= 3)
            {
                break;
            }
            if (count == 0)
            {
                maxElem = elem;
            }
            else if (count == 2)
            {
                thirdElem = elem;
            }
            ++count;
        }
        if (count >= 3)
        {
            return thirdElem;
        }
        else
        {
            return maxElem;
        }
    }
};

class Solution2
{
public:
    int thirdMax(vector<int> &nums)
    {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for (long num : nums)
        {
            if (num > a) // 更新最大值 a 及 b c
            {
                c = b;
                b = a;
                a = num;
            }
            else if (a > num && num > b) // 更新次大值 b 及 c
            {
                c = b;
                b = num;
            }
            else if (b > num && num > c) // 更新最小值 c
            {
                c = num;
            }
        }
        return c == LONG_MIN ? a : c;
    }
};