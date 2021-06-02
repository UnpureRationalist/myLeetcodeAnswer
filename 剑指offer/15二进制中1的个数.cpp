#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n & 1);
            n >>= 1;
        }
        return sum;
    }
};

class Solution2
{
public:
    int hammingWeight(int n)
    {
        int res = 0;
        while (n != 0)
        {
            res++;
            n &= n - 1; // 消去 n 最右边的 1
        }
        return res;
    }
};

int main()
{

    return 0;
}