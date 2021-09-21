#include <iostream>
#include <vector>
using namespace std;

// 深搜
class Solution
{
    int count = 0;
    int n;
    vector<int> sums;

    void dfs(vector<int> &nums, int start, int already, int target)
    {
        if (start == n)
        {
            count += already == target;
            return;
        }
        if (already + sums[start] < target || already - sums[start] > target)
            return;
        dfs(nums, start + 1, already + nums[start], target);
        dfs(nums, start + 1, already - nums[start], target);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        n = nums.size();
        sums.resize(n);
        sums[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            sums[i] = sums[i + 1] + nums[i];
        }
        dfs(nums, 0, 0, target);
        return count;
    }
};

// 动态规划
class Solution2
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int &num : nums)
        {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0)
        {
            return 0;
        }
        int n = nums.size(), neg = diff / 2;
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= num)
                {
                    dp[i][j] += dp[i - 1][j - num];
                }
            }
        }
        return dp[n][neg];
    }
};

int main()
{

    return 0;
}