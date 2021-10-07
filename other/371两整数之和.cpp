#include <iostream>
using namespace std;

class Solution
{
    int getBit(int n, int i)
    {
        return (n >> i) & 1;
    }

    int setBit(int n, bool bit, int i)
    {
        if (bit)
        {
            // 逻辑 |
            int temp = 1 << i;
            n |= temp;
        }
        else
        {
            int temp = ~(1 << i);
            n &= temp;
        }
        return n;
    }

public:
    /**
     *  a   b   pro   本位    进位
     *  0   0   0       0       0
     *  0   1   0       1       0
     *  1   0   0       1       0
     *  1   1   0       0       1
     *  0   0   1       1       0
     *  0   1   1       0       1
     *  1   0   1       0       1
     *  1   1   1       1       1
     *               a^b^pro    pro&(a^b)|(a&b)
     */
    int getSum(int a, int b)
    {
        int n = sizeof(int) * 8;
        bool s = 0, pro = 0; // 本位和、进位
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            bool bita = getBit(a, i);
            bool bitb = getBit(b, i);
            s = pro ^ bita ^ bitb;
            pro = pro & (bita ^ bitb) | (bita & bitb);
            ans = setBit(ans, s, i);
        }
        return ans;
    }
};

class Solution2
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};