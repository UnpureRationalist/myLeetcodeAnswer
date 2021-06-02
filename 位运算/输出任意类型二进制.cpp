#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
string showBit(T n)
{
    string res;
    int bit_width = sizeof(n) * 8; // 二进制位数
    for (int i = 0; i < bit_width; ++i, n >>= 1)
        res.push_back((1 & n) ? '1' : '0');
    reverse(res.begin(), res.end()); // 翻转
    return res;
}

string showBit(float f)
{
    int *pi = reinterpret_cast<int *>(&f); // 强制类型转换
    return showBit<int>(*pi);
}

string showBit(double d)
{
    long long *pl = reinterpret_cast<long long *>(&d);
    return showBit<long long>(*pl);
}

string showBit(long double d)
{
    long long *pl = reinterpret_cast<long long *>(&d);
    return showBit<long long>(*pl);
}

int main()
{
    cout << showBit(INT_MAX) << endl;
    cout << showBit(INT_MIN) << endl;
    cout << showBit(UINT32_MAX) << endl;
    cout << showBit(-1) << endl;
    cout << showBit('a') << endl;
    cout << showBit(1.2f) << endl;
    cout << showBit(1.2) << endl;
    cout << showBit(static_cast<long double>(0.0)) << endl;
    cout << showBit(0.0) << endl;
    return 0;
}