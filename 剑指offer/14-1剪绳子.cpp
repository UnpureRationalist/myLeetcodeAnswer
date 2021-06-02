#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/

class Solution
{
public:
    int cuttingRope(int n)
    {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i < n + 1; i++)
        {
            for (int j = 2; j < i; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

class Solution2
{
public:
    int cuttingRope(int n)
    {
        if (n <= 3)
            return n - 1;
        int a = n / 3, b = n % 3;
        if (b == 0)
            return (int)pow(3, a);
        if (b == 1)
            return (int)pow(3, a - 1) * 4;
        return (int)pow(3, a) * 2;
        // 简化： return n <= 3? n - 1 : pow(3, n / 3) * 4 / (4 - n % 3);
    }
};

int
main()
{
    Solution s;
    cout << s.cuttingRope(10) << endl;
    return 0;
}