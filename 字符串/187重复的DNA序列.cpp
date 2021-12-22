#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;

        int n = s.length();
        if (n > 10)
        {
            string str = s.substr(0, 10);
            unordered_map<string, int> mp;
            mp.insert({str, 1});
            int i = 10;
            for (; i < n; ++i)
            {
                str = s.substr(i - 9, 10);
                auto iter = mp.find(str);
                if (iter == mp.end())
                {
                    mp.insert({str, 1});
                }
                else
                {
                    int times = iter->second;
                    if (times == 1)
                    {
                        mp[str] = 2;
                        res.push_back(str);
                    }
                }
            }
        }

        return res;
    }
};

class Solution2
{
    const int L = 10;

public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        unordered_map<string, int> cnt;
        int n = s.length();
        for (int i = 0; i <= n - L; ++i)
        {
            string sub = s.substr(i, L);
            if (++cnt[sub] == 2)
            {
                ans.push_back(sub);
            }
        }
        return ans;
    }
};

class Solution3
{
    const int L = 10;
    unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        int n = s.length();
        if (n <= L)
        {
            return ans;
        }
        int x = 0;
        for (int i = 0; i < L - 1; ++i)
        {
            x = (x << 2) | bin[s[i]];
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i <= n - L; ++i)
        {
            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << (L * 2)) - 1);
            if (++cnt[x] == 2)
            {
                ans.push_back(s.substr(i, L));
            }
        }
        return ans;
    }
};