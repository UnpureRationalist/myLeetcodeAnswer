#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        vector<int> length;
        for (auto &str : strs)
            length.push_back(str.length());
        int min_len = *min_element(length.begin(), length.end());
        string res;
        for (int i = 0; i < min_len; ++i)
        {
            char c = strs[0][i];
            int j = 1;
            for (; j < strs.size(); ++j)
            {
                if (c != strs[j][i])
                {
                    break;
                }
            }
            if (j == strs.size())
            {
                res.push_back(c);
            }
            else
            {
                break;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}