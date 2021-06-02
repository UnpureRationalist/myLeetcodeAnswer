#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    long double N, cur;
    long double a = 2.0, b = 3.0, c = 32.0;
    long double div = a / b;
    int x, y;
    cin >> N >> x >> y;
    cur = N;
    int day = 1;
    while (day <= y)
    {
        cur *= div;
        if (day == x)
            cur += N / a;
        if (cur < N / c)
            break;
        day++;
    }
    if (day > y)
        cout << "YE5!" << endl
             << setiosflags(ios::fixed) << setprecision(6) << cur;
    else
        cout << "N0!" << endl
             << day << " " << setiosflags(ios::fixed) << setprecision(6) << cur;
    return 0;
}