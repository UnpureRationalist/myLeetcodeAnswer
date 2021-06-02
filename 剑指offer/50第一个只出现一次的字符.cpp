#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        if (s.empty())
            return ' ';
        vector<int> hash(26, 0);
        for (auto c : s)
            ++hash[c - 'a'];
        for (auto c : s)
            if (hash[c - 'a'] == 1)
                return c;
        return ' ';
    }
};

int main()
{

    return 0;
}