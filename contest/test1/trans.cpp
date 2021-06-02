#include <iostream>
#include <string>
using namespace std;

string h2b[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
string hex2bin(const string &s)
{
    string res;
    int length = s.length();
    for (int i = 0; i < length; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            res = res + h2b[s[i] - '0'];
        else if (s[i] >= 'a' && s[i] <= 'f')
            res = res + h2b[s[i] - 'a' + 10];
        else if (s[i] >= 'A' && s[i] <= 'F')
            res = res + h2b[s[i] - 'A' + 10];
    }
    return res;
}

int hex2dec(const string &s)
{
    int sum = 0;
    int length = s.length();
    for (int i = 0; i < length; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            sum = sum * 16 + (s[i] - '0');
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            sum = sum * 16 + (s[i] - 'a' + 10);
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            sum = sum * 16 + (s[i] - 'A' + 10);
        }
    }
    return sum;
}

int main()
{
    string s;
    cin >> s;
    cout << hex2bin(s) << " " << hex2dec(s) << endl;
    return 0;
}