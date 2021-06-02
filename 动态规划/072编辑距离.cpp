#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
    经典动态规划问题： 编辑距离
    题意：给定两个字符串 s1 s2 ，问通过插入、删除、替换三种操作，最少经过多少次可以将 s1 转化为 s2
    问题分析：
        字符串 dp 问题一般套路：用两个指针 i j 分别指向两个字符串末尾，然后一步一步向前走，缩小问题规模

        base case: i 走完 s1 或者 j 走完 s2，此时返回未走完的字符串长度即可
                   若 i 走完 j 未走完，此时在 s1 前连续插入 s2 未走过子串长度即可
                   若 j 走完 i 未走完，此时连续删除 s1 未走过的子串即可
        
        dp 数组定义： dp[i][j] 表示 s1[0...i] 和 s2[0...j] 的最小编辑距离，那么 dp[s1.length()-1][s2.length()-1] 即为最终结果
        
        状态转移方程：
                      dp[i][j] = dp[i-1][j-1]                                       if s1[i] == s2[j]
                                 min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1      if s1[i] != s2[j]
                                       删除          插入          替换
*/
class Solution
{
public:
    int minDistance(const string &word1, const string &word2)
    {
        int row = word1.length(), col = word2.length();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        // 边界条件 隐含 dp[0][0] = 0
        for (int i = 1; i <= row; ++i) // j 走完 i 未走完
            dp[i][0] = i;
        for (int j = 1; j <= col; ++j) // i 走完 j 未走完
            dp[0][j] = j;
        // 递推求解
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                if (word1[i - 1] == word2[j - 1]) // 注意： 下标减一 !!!
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
        return dp[row][col];
    }
};

int main()
{

    return 0;
}