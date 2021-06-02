#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k; // row col selectTimes
const int MAX = 1010;
char a[MAX][MAX];
char sel[MAX][10];
bool legalPos(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#')
        return true;
    return false;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < k; ++i)
        cin >> sel[i];

    int sx = 0, sy = 0;
    for (; sx < n; ++sx)
    {
        for (; sy < m; ++sy)
        {
            if (a[sx][sy] == '@')
                break;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        string s = sel[i];
        switch (s[0])
        {
        case 'E':
            for (; legalPos(sx, sy); ++sy)
                ;
            --sy;
            break;
        case 'S':
            for (; legalPos(sx, sy); ++sx)
                ;
            --sx;
            break;
        case 'W':
            for (; legalPos(sx, sy); --sy)
                ;
            ++sy;
            break;
        case 'N':
            for (; legalPos(sx, sy); --sx)
                ;
            ++sx;
            break;
        }
    }
    cout << sx + 1 << " " << sy + 1 << endl;
    return 0;
}