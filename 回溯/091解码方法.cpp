#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] != '0')
            {
                f[i] += f[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26))
            {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};

class Solution2
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        // a = f[i-2], b = f[i-1], c = f[i]
        int a = 0, b = 1, c;
        for (int i = 1; i <= n; ++i)
        {
            c = 0;
            if (s[i - 1] != '0')
            {
                c += b;
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26))
            {
                c += a;
            }
            tie(a, b) = {b, c};
        }
        return c;
    }
};

class Solution3
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        s = " " + s;
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            int a = s[i] - '0', b = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (1 <= a && a <= 9)
                f[i] = f[i - 1];
            if (10 <= b && b <= 26)
                f[i] += f[i - 2];
        }
        return f[n];
    }
};

class Solution4
{
public:
    int numDecodings(string s)
    {
        dp = vector<int>(s.length(), -1);
        return dfs(0, s);
    }

    int dfs(int pos, const string &s)
    {
        // 到了字符串末尾
        if (pos == s.length())
            return 1;
        // 之前搜索过这种情况
        if (dp[pos] != -1)
            return dp[pos];
        // 0 返回0
        if (s[pos] == '0')
            return dp[pos] = 0;

        // 考虑只转换当前一位和转换两位
        int ans = 0;
        ans += dfs(pos + 1, s);
        int tmp = 0;
        if (pos + 1 < s.length())
        {
            tmp = (s[pos] - '0') * 10 + s[pos + 1] - '0';
            if (tmp <= 26)
                ans += dfs(pos + 2, s);
        }
        return dp[pos] = ans;
    }

private:
    vector<int> dp, ans;
};

int main()
{

    return 0;
}