#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    string palindrome(const string &s, int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r]) // 双指针
        {
            --l;
            ++r;
        }
        return s.substr(l + 1, r - l - 1);
    }

public:
    string longestPalindrome(string s)
    {
        string res;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            res = res.length() >= s1.length() ? res : s1;
            res = res.length() >= s2.length() ? res : s2;
        }
        return res;
    }
};

// 动态规划法
class Solution2
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l)
        {
            for (int i = 0; i + l < n; ++i)
            {
                int j = i + l;
                if (l == 0)
                {
                    dp[i][j] = 1;
                }
                else if (l == 1)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size())
                {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}