#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
    bool isLegal(const string &s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }

    bool notContain(const string &s, const set<char> &cset)
    {
        for (auto &c : s)
            if (cset.find(c) != cset.end())
                return false;
        return true;
    }

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param inputStr string字符串 输入的长字符串
     * @param cList char字符型vector 需要被排除的字符集合
     * @return int整型
     */
    int specialStr(string inputStr, vector<char> &cList)
    {
        // write code here
        set<char> cset(cList.begin(), cList.end());
        int n = inputStr.length();
        int res = 1;
        for (int i = 0; i < n; ++i)
        {
            if (notContain(string(1, inputStr[i]), cset))
            {
                for (int j = i + 1; j < n; ++j)
                {
                    int len = j - i;
                    string str = inputStr.substr(i, len);
                    if (notContain(str, cset) && isLegal(str))
                    {
                        res = max(res, len);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}