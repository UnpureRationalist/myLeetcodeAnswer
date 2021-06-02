#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> preMin(n, INT_MAX);
        for (int i = 1; i < n; ++i)
            preMin[i] = min(preMin[i - 1], prices[i - 1]);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (preMin[i] != INT_MAX)
            {
                ans = max(prices[i] - preMin[i], ans);
            }
        }
        return ans;
    }
};

class Solution2
{
public:
    int maxProfit(vector<int> &prices)
    {
        int inf = INT_MAX;
        int minprice = inf, maxprofit = 0;
        for (int price : prices)
        {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};

int main()
{

    return 0;
}