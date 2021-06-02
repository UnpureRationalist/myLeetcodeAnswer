#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if(n <= 0)
            return false;
        int count = -1, bit;
        while (n)
        {
            bit = n & 1;
            if (bit == 1 && n != 1)
                return false;
            n >>= 1;
            count++;
        }
        return (count % 2) == 0;
    }
};

int main()
{

    return 0;
}