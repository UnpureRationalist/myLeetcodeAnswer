#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int n = prices.size();
        for (int i = 0; i < n; ++i)
        {
            int minElem = *min_element(prices.begin(), prices.begin() + i + 1);
            int maxElem = *max_element(prices.begin() + i, prices.end());
            res = max(res, maxElem - minElem);
        }
        return res;
    }
};

class Solution2
{
public:
    int maxProfit(vector<int> &prices)
    {
        int inf = 1e9;
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