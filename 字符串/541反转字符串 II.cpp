#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
    void reverse(string &s, int start, int k)
    {
        std::reverse(s.begin() + start, s.begin() + start + k);
    }

public:
    string reverseStr(string s, int k)
    {
        int n = s.length();
        int step = k << 1;
        int end = n - (n % step);
        int i = 0;
        for (; i < end; i += step)
        {
            reverse(s, i, k);
        }
        int leftLength = min(k, n - end);
        reverse(s, end, leftLength);
        return s;
    }
};

int main()
{

    return 0;
}