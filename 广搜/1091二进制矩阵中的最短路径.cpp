#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    int n;

    bool isLegal(int x, int y)
    {
        if (x >= 0 && x < n && y >= 0 && y < n)
            return true;
        return false;
    }
    int dir[8][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        if(grid[0][0] == 1)
            return -1;
        q.push(pair<int, int>(0, 0));
        visited[0][0] = 1;
        int count = 0;
        while (!q.empty())
        {
            count++;
            int size = q.size();
            while (size--)
            {
                auto pos = q.front();
                q.pop();
                int x = pos.first, y = pos.second;
                if (x == n - 1 && y == n - 1)
                    return count;
                // 入队
                for (int i = 0; i < 8; ++i)
                {
                    int px = x + dir[i][0], py = y + dir[i][1];
                    if (isLegal(px, py) && grid[px][py] == 0 && visited[px][py] == 0)
                    {
                        visited[px][py] = 1;
                        q.push(pair<int, int>(px, py));
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}