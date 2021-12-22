#include <iostream>
using namespace std;

int main()
{
    int a = -125;
    int k = 1;
    int b = a >> k;                  // 向下舍入(取整)
    int c = a / 2;                   // 除法
    int d = (a + (1 << k) - 1) >> k; // 向上舍入(取整)
    cout << a << "  " << b << "  " << c << "  " << d << endl;
    // 输出：-125  -63  -62  -62
    return 0;
}