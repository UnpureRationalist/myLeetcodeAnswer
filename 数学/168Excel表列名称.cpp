#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans;
        while (columnNumber)
        {
            int a0 = (columnNumber - 1) % 26 + 1;
            ans.push_back(a0 - 1 + 'A');
            columnNumber = (columnNumber - a0) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}