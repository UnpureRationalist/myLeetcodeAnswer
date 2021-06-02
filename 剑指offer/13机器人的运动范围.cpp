#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int row, col, k;
    int dir[4][2] = {{0, 1},  {1, 0}}; // {0, -1},  , {-1, 0}

public:
    int movingCount(int m, int n, int k)
    {
        vector<vector<bool>> visited(m, vector<bool>(n));
        row = m;
        col = n;
        this->k = k;
        int count = 0;
        dfs(0, 0, visited, count);
        return count;
    }

    int getBit(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isLegal(int i, int j)
    {
        if (i >= 0 && i < row && j >= 0 && j < col && (getBit(i) + getBit(j) <= k))
            return true;
        return false;
    }

    void dfs(int x, int y, vector<vector<bool>> &visited, int &count)
    {
        if (!isLegal(x, y) || visited[x][y])
            return;

        if (isLegal(x, y) && !visited[x][y])
        {
            visited[x][y] = true;
            count++;
            int r, c;
            for (int i = 0; i < 2; ++i)
            {
                r = x + dir[i][0];
                c = y + dir[i][1];
                if (isLegal(r, c) && !visited[r][c])
                    dfs(r, c, visited, count);
            }
        }
    }
};

int main()
{
    Solution s;
    cout << s.movingCount(2, 3, 1) << endl;
    return 0;
}