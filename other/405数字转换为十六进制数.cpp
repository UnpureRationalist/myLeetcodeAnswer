#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
    char get4Bit(int num, int index)
    {
        char c = 0;
        for (int i = 4 * index; i < 4 * (index + 1); ++i)
        {
            int moveBit = 31 - i;
            int bit = (num >> moveBit) & 1;
            int charBit = i - (4 * index);
            c |= (bit << (3 - charBit));
        }
        if (c < 10)
        {
            c = c + '0';
        }
        else
        {
            c = 'a' + c - 10;
        }
        return c;
    }

public:
    string toHex(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        string res;
        for (int i = 0; i < 8; ++i)
        {
            res.push_back(get4Bit(num, i));
        }
        if (num > 0)
        {
            string temp;
            int i = 0;
            for (; i < res.length(); ++i)
            {
                if (res[i] != '0')
                {
                    break;
                }
            }
            res = res.substr(i);
        }
        return res;
    }
};