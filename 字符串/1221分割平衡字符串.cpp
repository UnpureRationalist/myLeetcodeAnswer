#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    void setZero(unordered_map<char, int> &mp)
    {
        mp['L'] = 0;
        mp['R'] = 0;
    }

    bool balance(unordered_map<char, int> &mp)
    {
        return mp['L'] == mp['R'] && mp['L'] != 0;
    }

public:
    int balancedStringSplit(string s)
    {
        auto n = s.length();
        unordered_map<char, int> mp;
        mp.insert({'L', 0});
        mp.insert({'R', 0});
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            mp[s[i]]++;
            if (balance(mp))
            {
                ans++;
                setZero(mp);
            }
        }
        return ans;
    }
};

class Solution2
{
public:
    int balancedStringSplit(string s)
    {
        int ans = 0, d = 0;
        for (char ch : s)
        {
            ch == 'L' ? ++d : --d;
            if (d == 0)
            {
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}