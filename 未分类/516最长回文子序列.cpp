#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--)
        {
            f[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    f[i][j] = f[i + 1][j - 1] + 2;
                }
                else
                {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return f[0][n - 1];
    }
};

int main()
{

    return 0;
}