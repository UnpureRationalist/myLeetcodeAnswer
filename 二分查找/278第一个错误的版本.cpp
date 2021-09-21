#include <iostream>
using namespace std;

class Solution
{
    bool isBadVersion(int version)
    {
    }

public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n;
        int res;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}