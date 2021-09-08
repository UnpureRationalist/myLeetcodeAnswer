#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
    unordered_set<char> set{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    bool isElemmentChar(char c)
    {
        return set.find(c) != set.end();
    }

public:
    string reverseVowels(string s)
    {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j)
        {
            while (i < n && !isElemmentChar(s[i]))
                ++i;
            while (j >= 0 && !isElemmentChar(s[j]))
                --j;
            if (i < j && i < n && j >= 0)
                swap(s[i], s[j]);
            ++i;
            --j;
        }
        return s;
    }
};

int main()
{

    return 0;
}