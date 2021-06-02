#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
private:
    int N;
    vector<int> pos;

    bool isLegal(int k, int j)
    {
        for (int i = 0; i < k; ++i)
        {
            if (pos[i] == j || abs(i - k) == abs(pos[i] - j))
                return false;
        }
        return true;
    }

    void solve(int k, vector<vector<string>> &res)
    {
        if (k == N)
        {
            // 构造 vector 放入 res
            vector<string> temp(N, string());
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    if (j == pos[i])
                        temp[i].push_back('Q');
                    else
                        temp[i].push_back('.');
                }
            }
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < N; ++i)
        {
            if (isLegal(k, i))
            {
                pos[k] = i;
                solve(k + 1, res);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->N = n;
        pos.resize(n + 1);
        vector<vector<string>> res;
        solve(0, res);
        return res;
    }
};

int main()
{
    Solution s;
    auto res = s.solveNQueens(4);
    return 0;
}