#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; // 商品数量 、 m 的倍数

long long solve(int n, int m, const vector<int> &price, long long maxIndex)
{
    long long row = n, col = maxIndex * m;
    vector<vector<long long>> dp(row + 1, vector<long long>(col + 1, 0));
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            
        }
    }

    return dp[row][col];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        vector<int> price(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> price[i];
            sum += price[i];
        }
        if (sum % m == 0)
        {
            cout << 0 << endl;
            continue;
        }
        long long upper = sum - (sum % m);
        long long maxIndex = upper / m;
        long long res = solve(n, m, price, maxIndex);
        cout << res << endl;
    }
    return 0;
}