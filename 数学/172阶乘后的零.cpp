#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        vector<int> res(6, 0);
        for (int j = 2; j <= n; ++j)
        {
            int i = j;
            while (i >= 2)
            {
                if (i % 2 == 0)
                {
                    ++res[2];
                    i /= 2;
                    continue;
                }
                else if (i % 3 == 0)
                {
                    i /= 3;
                }
                else if (i % 5 == 0)
                {
                    ++res[5];
                    i /= 5;
                }
                else
                {
                    break;
                }
            }
        }
        return min(res[2], res[5]);
    }
};

class Solution2
{
public:
    int trailingZeroes(int n)
    {
        int zeroCount = 0;
        while (n > 0)
        {
            n /= 5;
            zeroCount += n;
        }
        return zeroCount;
    }
};

class Solution3
{
public:
    int trailingZeroes(int n)
    {
        vector<int> res(6, 0);
        for (int j = 2; j <= n; ++j)
        {
            int i = j;
            while (i >= 2)
            {
                if (i % 5 == 0)
                {
                    ++res[5];
                    i /= 5;
                }
                else
                {
                    break;
                }
            }
        }
        return res[5];
    }
};

int main()
{

    return 0;
}