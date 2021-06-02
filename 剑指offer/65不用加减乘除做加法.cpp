#include <iostream>
using namespace std;

class Solution
{
    int a = 666;
    // int b = 999;

public:
    virtual int add(int a, int b)
    {
        if (b == 0)
            return a;

        // 转换成非进位和 + 进位
        return add(a ^ b, static_cast<unsigned int>(a & b) << 1);
    }

    virtual int sub(int a, int b)
    {
        return a - b;
    }
};

class Derived : public Solution
{
public:
    int sub(int a, int b)
    {
        return a - b;
    }
};

int main()
{
    Solution s;
    cout << sizeof(s) << endl;
    cout << "&s = " << &s << endl;
    int *p = reinterpret_cast<int *>(&s);
    cout << "p[0] = " << p[0] << endl;
    cout << "p[1] = " << p[1] << endl;
    cout << "p[2] = " << p[2] << endl;
    cout << "p[3] = " << p[3] << endl;

    Derived d;
    cout << sizeof(d) <<endl;
    cout << "&d = " << &d << endl;
    p = reinterpret_cast<int *>(&d);
    cout << "p[0] = " << p[0] << endl;
    cout << "p[1] = " << p[1] << endl;
    cout << "p[2] = " << p[2] << endl;
    cout << "p[3] = " << p[3] << endl;
    return 0;
}