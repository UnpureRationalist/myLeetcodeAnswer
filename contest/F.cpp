#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isGoodWord(const string &s)
{
    if(s.length() <= 1)
        return false;
    if(!isupper(s[0]))
        return false;
    int length = s.length();
    for(int i = 1; i < length; ++i)
    {
        if(!islower(s[i]))
            return false;
    }
    return true;
}

bool isGoodStr(const string &s)
{
    
    return true;
}
int main()
{
    string s;
    while(getline(cin , s))
    {
        cout << s << endl;
    }
    return 0;
}