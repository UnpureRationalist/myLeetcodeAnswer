#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // dp[i] 表示以第 i 个数结尾的子数组和最大值
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i)
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{

    return 0;
}