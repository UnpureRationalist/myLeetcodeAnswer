#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

class Solution
{
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs,
                       int cost = 0, int k = 0)
    {
        if (k == special.size())
            return inner_product(begin(needs), end(needs), begin(price), cost);
        int ret = shoppingOffers(price, special, needs, cost, k + 1);
        if (!inner_product(begin(needs), end(needs), begin(special[k]), false, bit_or(), less()))
        {
            transform(begin(needs), end(needs), begin(special[k]), begin(needs), minus());
            ret = min(ret, shoppingOffers(price, special, needs, cost + special[k].back(), k));
            transform(begin(needs), end(needs), begin(special[k]), begin(needs), plus());
        };
        return ret;
    }
};