#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int row, col;
    int dir[4][2] = { {0,1},
                     {0,-1},
                     {1,0},
                     {-1,0} };
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        row = board.size();
        col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        for(int i = 0;i < row; ++i)
        {
            for(int j = 0;j < col; ++j)
            {
                visited[i][j] = true;
                if(board[i][j] == word[0] && dfs(board, string(1, board[i][j]), word, i, j, visited))
                    return true;
                visited[i][j] = false;
            }
        }
        return false;
    }

    bool isLegal(int i, int j)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
            return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, string now, string word, int x, int y, vector<vector<bool>> &visited)
    {
        if(now.length() > word.length())
            return false;
        if(now == word)
            return true;
        if(now.length() == word.length())
            return false;
        for(int i = 0;i < 4; ++i)
        {
            int r = x+dir[i][0], c = y+dir[i][1];
            if(isLegal(r, c) && !visited[r][c])
            {
                visited[r][c] = true;
                if(board[r][c] == word[now.length()] && dfs(board, now+board[r][c], word, r, c, visited))
                    return true;
                visited[r][c] = false;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}