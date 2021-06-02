#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        double low = 0, high = x;
        double res = x;
        while (abs(res * res - x) >= 1e-2)
        {
            res = (low + high) / 2;
            double square = res * res;
            if (square < x)
            {
                low = res;
            }
            else if (square > x)
            {
                high = res;
            }
            else
                break;
        }
        return res;
    }
};

// 牛顿迭代法
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        
        double C = x, x0 = x;
        while (true)
        {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7)
            {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(1) << endl;
    return 0;
}