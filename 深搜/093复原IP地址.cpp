#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
    vector<string> res;
    vector<int> indexs;
    int n;

    bool isLegalNum(string s)
    {
        if (s.length() > 1 && s[0] == '0')
            return false;
        int num = atoi(s.c_str());
        return num >= 0 && num <= 255;
    }

    void help(string s, int pos, int level)
    {
        if (level == 3)
        {
            if (pos < n && isLegalNum(s.substr(pos)))
            {
                // 构造 string
                string temp;
                int count = 0;
                for (int i = 0; i < n; ++i)
                {
                    temp.push_back(s[i]);
                    if (count < 3 && indexs[count] == i)
                    {
                        temp.push_back('.');
                        ++count;
                    }
                }
                res.push_back(temp);
            }
            return;
        }
        int MAX = min(pos + 3, n);
        for (int i = pos; i < MAX; ++i)
        {
            int len = i - pos + 1;
            string num = s.substr(pos, len);
            if (isLegalNum(num))
            {
                indexs[level] = i;
                help(s, i + 1, level + 1); // 深搜
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        n = s.length();
        indexs.resize(3);
        help(s, 0, 0);
        return res;
    }
};

int main()
{

    return 0;
}