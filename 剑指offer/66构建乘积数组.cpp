#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        int n = a.size();
        vector<int> res(n, 1);
        if (n == 0)
            return res;
        int left = 1, right = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] *= left;
            left *= a[i]; // 持有左边的所有数的乘积

            res[n - i - 1] *= right;
            right *= a[n - i - 1]; // 持有右边的所有数的乘积
        }
        return res;
    }
};

int main()
{

    return 0;
}