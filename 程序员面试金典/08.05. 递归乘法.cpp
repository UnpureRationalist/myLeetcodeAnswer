#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int mul(int big, int small, int base)
    {
        if (big == 0 || small == 0)
            return 0;
        int lower = small & 1;
        if (lower == 1)
        {
            return (big << base) + mul(big, small >> 1, base + 1);
        }
        else
        {
            return mul(big, small >> 1, base + 1);
        }
    }

public:
    int multiply(int A, int B)
    {
        return mul(max(A, B), min(A, B), 0);
    }
};

int main()
{
    Solution s;
    cout << s.multiply(30234, 41342) << endl;
    return 0;
}