#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 1)
                dp[i][0] = 0; // 有障碍 0
            else
            {
                if ((i == 1 || i == 0) && obstacleGrid[0][0] == 0)
                    dp[i][0] = 1; // 第一个位置特殊考虑
                else
                    dp[i][0] = dp[i - 1][0]; // 递推
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (obstacleGrid[0][j] == 1)
                dp[0][j] = 0;
            else
            {
                if ((j == 1 || j == 0) && obstacleGrid[0][0] == 0)
                    dp[0][j] = 1;
                else
                    dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{

    return 0;
}