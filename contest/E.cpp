#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<char> n(100005, '\0');
string s;
int main()
{
    unsigned long long V, v;
    unsigned long long total = 0;
    unsigned long long cnt = 0;
    cin >> V;
    cin >> s;
    v = V;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            if (v > 0)
            {
                v--;
                cnt++;
                n[cnt - 1] = s[i];
                total = total + cnt;
            }
            else
            {
                for (int j = 0; j < cnt; j++)
                {
                    if (n[j] == '2')
                    {
                        n[j] = '1';
                        v++;
                        break;
                    }
                }
                total = total + cnt;
            }
        }
        if (s[i] == '2')
        {
            if (v > 1)
            {
                v = v - 2;
                cnt++;
                n[cnt - 1] = s[i];
                total = total + cnt;
            }
            else
            {
                total = total + cnt;
            }
        }
    }
    cout << total;
    return 0;
}