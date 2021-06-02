#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
    在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
    你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
    给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
*/
/*
    令 dp[i][j] 表示从 (i,j) 出发到达右下角位置能够获得的最大价值
    则 dp[i][j] = grid[i][j] + max(dp[i][j+1], dp[i+1][j])
    边界条件：
        最下面一行和最右面一列为边界条件，它们只能不断向右或者向下走
*/
class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = m != 0 ? grid[0].size() : 0;
        vector<vector<int>> dp(m, vector<int>(n));
        // base case
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 2; i >= 0; --i)
            dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
        for (int j = n - 2; j >= 0; --j)
            dp[m - 1][j] = dp[m - 1][j + 1] + grid[m - 1][j];
        // dp
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                dp[i][j] = grid[i][j] + max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};

int main()
{

    return 0;
}