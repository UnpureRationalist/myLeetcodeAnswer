#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        // 设 i 行满，共 i*(1+i)/2 个元素
        long long i = 1;
        while (i * (i + 1) / 2 < n)
        {
            ++i;
        }
        if (i * (i + 1) / 2 > n)
        {
            --i;
        }
        return i;
    }
};

class Solution2
{
public:
    int arrangeCoins(int n)
    {
        return (int)((sqrt((long long)8 * n + 1) - 1) / 2);
    }
};