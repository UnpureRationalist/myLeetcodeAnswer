#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    vector<int> square;

public:
    int numSquares(int n)
    {
        square.resize(101);
        for (int i = 1; i < 101; ++i)
            square[i] = i * i;
        vector<int> dp(max(n + 1, 10), INT_MAX);
        for (int i = 1; i <= 3; ++i)
            dp[i] = i;
        dp[4] = 1;
        for (int i = 5; i <= n; ++i)
        {
            int sq = sqrt(i);
            if (sq * sq == i)
                dp[i] = 1;
            else
            {
                for (int j = 1; j <= 100; ++j)
                {
                    if (square[j] < i)
                    {
                        dp[i] = min(dp[i], 1 + dp[i - square[j]]);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

class Solution
{

public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        // bottom case
        dp[0] = 0;

        // pre-calculate the square numbers.
        int max_square_index = sqrt(n) + 1;
        vector<int> square_nums(max_square_index);
        for (int i = 1; i < max_square_index; ++i)
        {
            square_nums[i] = i * i;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int s = 1; s < max_square_index; ++s)
            {
                if (i < square_nums[s])
                    break;
                dp[i] = min(dp[i], dp[i - square_nums[s]] + 1);
            }
        }
        return dp[n];
    }
};


/*

可以按照上面的例子来实现解决方案。

首先，我们检查数字 n 的形式是否为 n = 4^{k}(8m+7)，如果是，则直接返回 4。
否则，我们进一步检查这个数本身是否是一个完全平方数，或者这个数是否可以分解为 2 个完全平方数和。
在底部的情况下，这个数可以分解为 3 个平方和，但我们也可以根据四平方定理，通过加零，把它分解为 4 个平方。
但是我们被要求找出最小的平方数。

*/
class Solution
{

protected:
    bool isSquare(int n)
    {
        int sq = (int)sqrt(n);
        return n == sq * sq;
    }

public:
    int numSquares(int n)
    {
        // four-square and three-square theorems.
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;

        if (isSquare(n))
            return 1;
        // enumeration to check if the number can be decomposed into sum of two squares.
        for (int i = 1; i * i <= n; ++i)
        {
            if (isSquare(n - i * i))
                return 2;
        }
        // bottom case of three-square theorem.
        return 3;
    }
};

int main()
{

    return 0;
}