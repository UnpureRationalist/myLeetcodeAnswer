#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        int twice = target << 1;
        vector<vector<int>> res;
        for (int m = 2; m < twice; ++m)
        {
            if (twice % m == 0)
            {
                int twiceK = (twice / m) + 1 - m;
                if (twiceK >= 2 && twiceK % 2 == 0)
                {
                    res.push_back(vector<int>());
                    int k = twiceK >> 1;
                    for (int i = k; i < k + m; ++i)
                    {
                        res.back().push_back(i);
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

class Solution2
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 等效于 target / 2 下取整
        for (int x = 1; x <= limit; ++x)
        {
            long long delta = 1 - 4 * (x - 1ll * x * x - 2 * target);
            if (delta < 0)
            {
                continue;
            }
            int delta_sqrt = (int)sqrt(delta + 0.5);
            if (1ll * delta_sqrt * delta_sqrt == delta && (delta_sqrt - 1) % 2 == 0)
            {
                int y = (-1 + delta_sqrt) / 2; // 另一个解(-1-delta_sqrt)/2必然小于0，不用考虑
                if (x < y)
                {
                    res.clear();
                    for (int i = x; i <= y; ++i)
                    {
                        res.emplace_back(i);
                    }
                    vec.emplace_back(res);
                }
            }
        }
        return vec;
    }
};

int main()
{

    return 0;
}