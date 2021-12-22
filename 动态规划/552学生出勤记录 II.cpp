#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

/**
 * 定义 dp[i][j][k] 表示前 i 天有 j 个 ‘A’ 且结尾有连续 k 个 ‘L’ 的可奖励的出勤记录的数量
 * 其中 0 ≤ i ≤ n， 0 ≤ j ≤ 1， 0 ≤ k ≤ 2
 * 
 * 边界条件：dp[0][0][0] = 0
 * 递推方程如下：
 */

class Solution
{
public:
    static constexpr int MOD = 1'000'000'007;

    int checkRecord(int n)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3))); // 长度，A 的数量，结尾连续 L 的数量
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            // 以 P 结尾的数量
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 0; k <= 2; k++)
                {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }
            // 以 A 结尾的数量
            for (int k = 0; k <= 2; k++)
            {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }
            // 以 L 结尾的数量
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
        }
        int sum = 0;
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 2; k++)
            {
                sum = (sum + dp[n][j][k]) % MOD;
            }
        }
        return sum;
    }
};

class Solution3
{
public:
    static constexpr int MOD = 1'000'000'007;

    int checkRecord(int n)
    {
        int dp[2][3] = {0}; // A 的数量，结尾连续 L 的数量
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int dpNew[2][3] = {0}; // A 的数量，结尾连续 L 的数量
            // 以 P 结尾的数量
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 0; k <= 2; k++)
                {
                    dpNew[j][0] = (dpNew[j][0] + dp[j][k]) % MOD;
                }
            }
            // 以 A 结尾的数量
            for (int k = 0; k <= 2; k++)
            {
                dpNew[1][0] = (dpNew[1][0] + dp[0][k]) % MOD;
            }
            // 以 L 结尾的数量
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    dpNew[j][k] = (dpNew[j][k] + dp[j][k - 1]) % MOD;
                }
            }
            memcpy(dp, dpNew, sizeof(dp));
        }
        int sum = 0;
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 2; k++)
            {
                sum = (sum + dp[j][k]) % MOD;
            }
        }
        return sum;
    }
};

class Solution1
{
public:
    static constexpr int MOD = 1'000'000'007;

    vector<vector<long>> pow(vector<vector<long>> mat, int n)
    {
        vector<vector<long>> ret = {{1, 0, 0, 0, 0, 0}};
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                ret = multiply(ret, mat);
            }
            n >>= 1;
            mat = multiply(mat, mat);
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>> a, vector<vector<long>> b)
    {
        int rows = a.size(), columns = b[0].size(), temp = b.size();
        vector<vector<long>> c(rows, vector<long>(columns));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                for (int k = 0; k < temp; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                    c[i][j] %= MOD;
                }
            }
        }
        return c;
    }

    int checkRecord(int n)
    {
        vector<vector<long>> mat = {{1, 1, 0, 1, 0, 0},
                                    {1, 0, 1, 1, 0, 0},
                                    {1, 0, 0, 1, 0, 0},
                                    {0, 0, 0, 1, 1, 0},
                                    {0, 0, 0, 1, 0, 1},
                                    {0, 0, 0, 1, 0, 0}};
        vector<vector<long>> res = pow(mat, n);
        long sum = accumulate(res[0].begin(), res[0].end(), 0ll);
        return (int)(sum % MOD);
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    cout << s.checkRecord(n) << endl;
    return 0;
}