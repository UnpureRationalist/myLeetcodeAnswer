#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            int newDp0 = max(dp0, dp1 + prices[i]);
            int newDp1 = max(dp1, dp0 - prices[i]);
            dp0 = newDp0;
            dp1 = newDp1;
        }
        return dp0;
    }
};

class Solution2
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i)
        {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}