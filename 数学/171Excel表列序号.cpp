#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int res = 0;
        long long base = 1;
        for (int i = columnTitle.length() - 1; i >= 0; --i)
        {
            int temp = (columnTitle[i] - 'A' + 1) * base;
            res += temp;
            base *= 26;
        }
        return res;
    }
};

int main()
{

    return 0;
}