#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        list<char> res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int pre = 0, sum = 0;
        while(i >= 0 && j >= 0)
        {
            sum = a[i] - '0' + b[j] - '0' + pre;
            pre = sum / 2;
            sum = sum % 2;
            char c = sum + '0';
            res.push_front(c);
            i--;
            j--;
        }
        while(i >= 0)
        {
            sum = a[i] - '0' + pre;
            pre = sum / 2;
            sum = sum % 2;
            char c = sum + '0';
            res.push_front(c);
            i--;
        }
        while (j >= 0)
        {
            sum =  b[j] - '0' + pre;
            pre = sum / 2;
            sum = sum % 2;
            char c = sum + '0';
            res.push_front(c);
            j--;
        }
        if(pre)
            res.push_front(pre + '0');
        return string(res.begin(), res.end());
    }
};

int main()
{
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    return 0;
}