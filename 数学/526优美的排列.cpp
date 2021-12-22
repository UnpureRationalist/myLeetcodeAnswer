#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int ans = 0;

    int n;

    bool judge(int elem, int i)
    {
        return (elem % i == 0) || (i % elem == 0);
    }

    vector<bool> used;

    void dfs(int depth)
    {
        if (depth == n)
        {
            ++ans;
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if ((!used[i]) && judge(i + 1, depth + 1))
            {
                used[i] = true;
                dfs(depth + 1);
                used[i] = false;
            }
        }
    }

public:
    int countArrangement(int n)
    {
        this->n = n;
        used.resize(n);
        dfs(0);
        return ans;
    }
};

class Solution
{
public:
    int countArrangement(int n)
    {
        vector<int> f(1 << n);
        f[0] = 1;
        for (int mask = 1; mask < (1 << n); mask++)
        {
            int num = __builtin_popcount(mask);
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i) && (num % (i + 1) == 0 || (i + 1) % num == 0))
                {
                    f[mask] += f[mask ^ (1 << i)];
                }
            }
        }
        return f[(1 << n) - 1];
    }
};

int main()
{

    return 0;
}