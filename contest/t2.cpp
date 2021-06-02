#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "ibti lbtlovebte lbtlibtinbtnkbtkebtezbas jebte dosadnbtna ovakbtkebtemibtijaxaszxdbtddbtddbtddbtddbtddbtd";
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'l' || s[i] == 'i' || s[i] == 'n' || s[i] == 'k' || s[i] == 'e')
        {
            cout << s[i];
            i += 3;
        }
        else
        {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}