#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int res = 0;
        while (x > 0 || y > 0)
        {
            int x_bit = x & 1;
            x >>= 1;
            int y_bit = y & 1;
            y >>= 1;
            res += x_bit != y_bit;
        }
        return res;
    }
};

int main() { return 0; }