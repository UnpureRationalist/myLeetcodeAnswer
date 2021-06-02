#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

// 利用 STL
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string perm(n, '0');
        iota(perm.begin(), perm.end(), '1');
        while (--k)
            next_permutation(perm.begin(), perm.end());
        return perm;
    }
};

// 回溯
class Solution2
{
    int count = 0;
    int k;
    int n;
    vector<int> v;
    vector<int> flag;
    string res;

    void solve(int i)
    {
        if (res.length() != 0)
            return;
        if (i == n)
        {
            ++count;
            if (count == k)
            {
                for (auto e : v)
                    res += to_string(e);
            }
            return;
        }
        for (int j = 0; j < n; ++j)
        {
            if (flag[j] == 0)
            {
                flag[j] = 1;
                v[i] = j + 1;
                solve(i + 1);
                flag[j] = 0; // 回溯
            }
        }
    }

public:
    string getPermutation(int n, int k)
    {
        this->n = n;
        this->k = k;
        v.resize(n);
        flag.resize(n);
        solve(0);
        return res;
    }
};

// 官方题解
class Solution3
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            factorial[i] = factorial[i - 1] * i;
        }

        --k;
        string ans;
        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            int order = k / factorial[n - i] + 1;
            for (int j = 1; j <= n; ++j)
            {
                order -= valid[j];
                if (!order)
                {
                    ans += (j + '0');
                    valid[j] = 0;
                    break;
                }
            }
            k %= factorial[n - i];
        }
        return ans;
    }
};

int main()
{
    Solution2 s;
    cout << s.getPermutation(3, 3);
    return 0;
}