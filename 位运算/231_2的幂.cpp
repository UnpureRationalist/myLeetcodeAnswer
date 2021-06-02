#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return (n & (n - 1)) == 0;
    }
};

int main() { return 0; }