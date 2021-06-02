#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (char &c : s)
            c = tolower(c);
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (!isalnum(s[i]))
                ++i;
            else if (!isalnum(s[j]))
                --j;
            else
            {
                if (s[i] != s[j])
                    return false;
                else
                {
                    ++i;
                    --j;
                }
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}