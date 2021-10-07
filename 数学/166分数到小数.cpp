#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        long long n = numerator, d = denominator;
        string res;
        // 判断正负号
        if (n * d < 0)
            res += "-";
        // 整数部分
        long long a = abs(n / d);
        res += to_string(a);
        // 分子分母全部变成正号
        if (n < 0)
            n *= -1;
        if (d < 0)
            d *= -1;
        // 取余
        n %= d;
        // 如果整除
        if (n == 0)
        {
            return res;
        }
        res += ".";
        // 计算小数部分
        int index = 0;
        string s;
        unordered_map<int, int> mp;
        while (n && !mp.count(n))
        {
            // 标记可能循环的位置
            mp[n] = index++;            // 存储余数
            n *= 10;                    // 模拟除法运算
            s.push_back((n / d + '0')); // 保存一位上的运算结果
            n %= d;                     // 更新余数
        }
        // 发生循环
        if (n != 0)
        {
            res += s.substr(0, mp[n]) + "(" + s.substr(mp[n]) + ")";
        }
        else
        {
            res += s;
        }
        return res;
    }
};