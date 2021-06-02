#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid.front().size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        int j = n - 1;
        int i = m - 2;
        for (; i >= 0; --i)
            dp[i][j] = dp[i + 1][j] + grid[i][j];
        i = m - 1;
        for (j = n - 2; j >= 0; --j)
            dp[i][j] = dp[i][j + 1] + grid[i][j];
        for (i = m - 2; i >= 0; --i)
        {
            for (j = n - 2; j >= 0; --j)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    cout << s.minPathSum(grid) << endl;
    return 0;
}