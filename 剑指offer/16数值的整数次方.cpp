#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        long long N = n;
        if (N < 0)
        {
            N = -N;
            x = 1 / x;
        }
        if(N%2)
        {
            return x * myPow(x, N-1);
        }
        else
        {
            double temp = myPow(x, N/2);
            return temp*temp;
        }
    }
};

int main()
{

    return 0;
}