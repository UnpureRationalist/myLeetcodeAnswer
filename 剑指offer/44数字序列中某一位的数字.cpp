#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
    数字范围    位数         数字个数           sum
    0-9         1 位        10 个数         10
    10-99       2 位        90 个数         10 + 2*90 = 190
    100-999     3 位        900             190 + 3*900 = 2890
    1000-9999   4 位        9000            ...
    ...                                     ...
                9 位        9*(10^8)
    2147483647  10 位       1147483648      ...
*/

class Solution
{
    // O(logn)
    int countDigit(int n)
    {
        if (n <= 9)
            return 1;
        int res = 0;
        while (n)
        {
            ++res;
            n /= 10;
        }
        return res;
    }

    int getBit(int n, int k)
    {
        if (k == 0)
            return n % 10;
        k = countDigit(n) + 1 - k;
        int res = 0;
        // O(logn)
        while (k--)
        {
            res = n % 10;
            n /= 10;
        }
        return res;
    }

public:
    int findNthDigit(int n)
    {
        if (n < 10)
            return n;
        const int MAX = 11;
        vector<long long> bit(MAX), count(MAX), sum(MAX, -1); // sum 初始化为 -1 ，序号从 0 开始
        // O(1)
        for (int i = 1; i < MAX; ++i)
            bit[i] = i;
        count[1] = 10;
        // O(1)
        for (int i = 2; i < MAX; ++i)
        {
            if (i == 10)
            {
                count[i] = 1147483648;
            }
            else
            {
                count[i] = 9 * pow(10, i - 1);
            }
        }
        // O(1)
        for (int i = 1; i < MAX; ++i)
            sum[i] = sum[i - 1] + bit[i] * count[i];

        // lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end
        // O(1)  因为数组长度固定，与 n 无关
        auto it = lower_bound(sum.begin() + 1, sum.end(), static_cast<long long>(n));

        if (*it == n) // 此情况必然为 9
            return 9;

        int numBit = it - sum.begin();  // 10进制数的位数
        int leftBitNum = n - *(it - 1); // 剩余的位数
        int div = leftBitNum / numBit;
        int mod = leftBitNum % numBit;
        int realNum = pow(10, numBit - 1) + (mod == 0 ? div - 1 : div); // mod == 0 需要特殊处理

        return getBit(realNum, mod);
    }
};

int main()
{
    Solution s;
    cout << "bit = " << s.findNthDigit(15) << endl;
    return 0;
}