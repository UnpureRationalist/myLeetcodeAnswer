#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> work;

int main()
{
    cin >> n;
    work.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> work[i];
    if (n == 1)
    {
        cout << work[0] << endl;
        return 0;
    }
    else if (n == 2)
    {
        cout << max(work[0], work[1]) << endl;
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(2));

    /*
        dp[i][0] 表示第 i 天不做题，前 i 天最多做几道题
        dp[i][1] 表示第 i 天做题，  前 i 天做多做几道题

        dp[i][0] = max( dp[i-1][0], dp[i-1][1], dp[i-2][1]     )

        dp[i][1] = work[i] + max( dp[i-1][0], dp[i-2][0], dp[i-2][1]    )
    */

    dp[0][0] = 0;
    dp[0][1] = work[0];
    dp[1][0] = work[0];
    dp[1][1] = work[1];

    for (int i = 2; i < n; ++i)
    {
        dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 2][1]);
        dp[i][1] = work[i] + max(dp[i - 1][0], max(dp[i - 2][0], dp[i - 2][1]));
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    return 0;
}