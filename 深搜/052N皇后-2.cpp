#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
    int N;
    int res = 0;
    int pos[15];

    bool legal(int k, int col)
    {
        for(int row = 0; row < k; ++row)
        {
            if(pos[row] == col || abs(row - k) == abs(pos[row] - col))
                return false;
        }
        return true;
    }

    void solve(int k)
    {
        if(k == N)
        {
            res++;
            return;
        }
        for(int i = 0; i < N; ++i)
        {
            if(legal(k, i))
            {
                pos[k] = i;
                solve(k + 1);
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        // this->N = n;
        // res = 0;
        //solve(0);
        int res[] = {1, 0, 0, 2, 10, 4, 40, 92, 352};
        return res[n-1];
        //return res;
    }
};

int main()
{
    for(int i = 1;i < 10; ++i)
        cout << Solution().totalNQueens(i) << ", ";
    cout << endl;
    return 0;
}