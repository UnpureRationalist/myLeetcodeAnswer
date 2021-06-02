#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        int n = haystack.length();
        int m = needle.length();
        // 暴力算法
        for (int i = 0; i < n - m + 1; ++i)
        {
            int j = 0;
            for (; j < m; ++j)
            {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == m)
                return i;
        }
        return -1;
    }
};

// KMP 算法
class Solution
{
public:
    int strStr(string s, string p)
    {
        int n = s.size(), m = p.size();
        if (m == 0)
            return 0;
        //设置哨兵
        s.insert(s.begin(), ' ');
        p.insert(p.begin(), ' ');
        vector<int> next(m + 1);
        //预处理next数组
        for (int i = 2, j = 0; i <= m; i++)
        {
            while (j && p[i] != p[j + 1])
                j = next[j];
            if (p[i] == p[j + 1])
                j++;
            next[i] = j;
        }
        //匹配过程
        for (int i = 1, j = 0; i <= n; i++)
        {
            while (j && s[i] != p[j + 1])
                j = next[j];
            if (s[i] == p[j + 1])
                j++;
            if (j == m)
                return i - m;
        }
        return -1;
    }
};

int main()
{

    return 0;
}