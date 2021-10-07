#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution2
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss;
        ss.str(s);
        string temp;
        while (ss >> temp)
            ;
        return temp.length();
    }
};

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        int n = s.length() - 1;
        while(n >= 0 && s[n] == ' ')
        {
            --n;
        }
        while (n >= 0 && s[n] != ' ')
        {
            ++ans;
            --n;
        }
        return ans;
    }
};