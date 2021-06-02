#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long w; // 员工数 、 奖金数(不需要全部用完)
struct Node
{
    int low, high;
};

vector<Node> input;

double ans = -1;
// vector<int> select;

void solve(int k, long long already, vector<int> select)
{
    if (k == n)
    {
        // 返回
        sort(select.begin(), select.end());
        if (n % 2 == 1)
        {
            ans = max(ans, double(select[n / 2]));
        }
        else
        {
            int mid = n / 2;
            ans = max(ans, double((select[mid] + select[mid - 1]) / 2.0));
        }
        return;
    }
    if (already >= w)
        return;
    int i = input[k].low;
    int MAX = input[k].high;
    for (; i <= MAX; ++i)
    {
        vector<int> next = select;
        next.push_back(i);
        solve(k + 1, already + i, next);
    }
}

int main()
{
    cin >> n >> w;
    input.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> input[i].low >> input[i].high;
    // select.resize(n);
    solve(0, 0, vector<int>());
    cout << ans << endl;
    return 0;
}