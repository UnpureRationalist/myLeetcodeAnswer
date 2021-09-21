#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int temp;
    while (cin >> temp)
    {
        v.push_back(temp);
    }

    int M = v.back();
    v.erase(v.end() - 1);

    sort(v.begin(), v.end());

    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] <= M)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (v[i] + v[j] <= M)
                {
                    ++ans;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}