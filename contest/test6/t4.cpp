#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> dirs{{-1, 0}, // up
                             {1, 0},  // down
                             {0, -1}, // left
                             {0, 1}}; // right
    int cost = INT_MAX;

    vector<vector<int>> map;

    vector<vector<bool>> visited;
    int row, col;

    bool isLegalPos(int i, int j)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            return map[i][j] != 2; // 2 means obstracles
        }
        return false;
    }

    int getCost(int i)
    {
        if (i == 0)
            return 2;
        return 1;
    }

    void dfs(int i, int j, int sum)
    {
        if (i == row - 1 && j == col - 1)
        {
            cost = min(sum, cost);
            return;
        }
        for (int i = 0; i < 4; ++i)
        {
            int x = i + dirs[i][0];
            int y = j + dirs[i][1];
            if (isLegalPos(x, y) && !visited[x][y] && (sum + getCost(map[x][y]) < cost))
            {
                visited[x][y] = true;
                dfs(x, y, sum + getCost(map[x][y]));
                visited[x][y] = false;
            }
        }
    }

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算最小航行费用
     * @param input int整型vector<vector<>> 二维网格
     * @return int整型
     */
    int minSailCost(vector<vector<int>> &input)
    {
        // write code here
        map = input; // save the map
        row = input.size();
        col = input.front().size();
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        visited[0][0] = true;
        dfs(0, 0, 0);
        return cost == INT_MAX ? -1 : cost;
    }
};

int main()
{

    return 0;
}