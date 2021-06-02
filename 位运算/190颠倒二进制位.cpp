#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int getBit(int n, int k) // 0-31 从左到右数
    {
        n >>= k;
        return 1 & n;
    }

    void setBit(uint32_t &n, int k, int value)
    {
        if (value == 0)
        {
            int base = 1 << k;
            base = ~base;
            n = n & base;
        }
        if (value == 1)
        {
            int base = 1 << k;
            n = n | base;
        }
    }

public:
    uint32_t reverseBits(uint32_t n)
    {
        int i = 0, j = 31;
        uint32_t res = n;
        while (i <= j)
        {
            int right = getBit(n, i);
            int left = getBit(n, j);
            setBit(res, j, right);
            setBit(res, i, left);
            i++;
            j--;
        }
        return res;
    }
};

int main()
{

    return 0;
}