#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int i = 0;
        int n = nums.size();
        for (; i < n; ++i)
        {
            if (nums[i] != v[i])
                break;
        }
        int j = n - 1;
        for (; j >= i; --j)
        {
            if (nums[j] != v[j])
                break;
        }
        return j - i + 1;
    }
};

int main()
{

    return 0;
}