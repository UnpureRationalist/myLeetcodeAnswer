#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        auto length = strs.size();
        vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        /*
            dp[i][j][k] 表示只取前 i 个子串，并且 0 的个数不超过 j 且 1 的个数不超过 k 的最大子集个数

        */

        for (int i = 1; i <= length; ++i)
        {
            vector<int> nums(2, 0);
            for (auto c : strs[i - 1])
                ++nums[c - '0'];
            for (int j = 0; j <= m; ++j)
            {
                for (int k = 0; k <= n; ++k)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    // 若当前字符串可以选取
                    if (nums[0] <= j && nums[1] <= k)
                    {
                        // 选取该字符串 与 不选取该字符串 取最大值
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - nums[0]][k - nums[1]] + 1);
                    }
                }
            }
        }

        return dp[length][m][n];
    }
};

class Solution2
{
public:
    vector<int> getZerosOnes(string &str)
    {
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++)
        {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int length = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < length; i++)
        {
            vector<int> &&zerosOnes = getZerosOnes(strs[i]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = m; j >= zeros; j--)
            {
                for (int k = n; k >= ones; k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{

    return 0;
}