#include <iostream>
#include <vector>
using namespace std;

int T;
int n;

const int MAX = 2000000010;
vector<int> input;
int maxElem = 0;

vector<int> res;

void solve(int maxElem)
{
    res.resize(max(maxElem + 1, 4));
    res[1] = 1;
    res[2] = 2;
    res[3] = 2;
    for (int i = 4; i <= maxElem; ++i)
    {
        if (i % 6 == 0)
        {
            // 3 choices
            res[i] = 1 + min(min(res[i / 3], res[i / 2]), res[i - 1]);
            continue;
        }
        else if (i % 3 == 0)
        {
            // 2 choices
            res[i] = 1 + min(res[i / 3], res[i - 1]);
        }
        else if (i % 2 == 0)
        {
            // 2 choices
            res[i] = 1 + min(res[i / 2], res[i - 1]);
        }
        else
        {
            // 1 choice
            res[i] = 1 + res[i - 1];
        }
    }
}

int main()
{
    cin >> T;
    int count = T;
    while (count--)
    {
        cin >> n;
        if (n > maxElem)
            maxElem = n;
        input.push_back(n);
    }
    solve(maxElem);
    for(int i = 0; i < T; ++i)
        cout << res[input[i]] << endl;
    return 0;
}