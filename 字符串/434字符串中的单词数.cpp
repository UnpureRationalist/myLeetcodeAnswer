#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countSegments(string s)
    {
        const char space = ' ';
        int ans = 0;
        int n = s.length();
        int i = 0;
        while (i < n && s[i] == space)
        {
            ++i;
        }
        while (i < n)
        {
            while (i < n && s[i] != space)
            {
                ++i;
            }
            ++ans;
            while (i < n && s[i] == space)
            {
                ++i;
            }
        }
        return ans;
    }
};