#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        auto n = s.length();
        map<char, char> mp;
        for (int i = 0; i < n; ++i)
        {
            if (mp.find(s[i]) == mp.end())
            {
                mp[s[i]] = t[i];
            }
            else
            {
                if (mp[s[i]] != t[i])
                    return false;
            }
        }
        map<char, int> mp2;
        for (auto &elem : mp)
        {
            ++mp2[elem.second];
        }
        for (auto &elem : mp2)
            if (elem.second > 1)
                return false;
        return true;
    }
};

int main()
{

    return 0;
}