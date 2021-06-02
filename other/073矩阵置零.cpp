#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool row = false, col = false;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0;i < m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                col = true;
                break;
            }
        }
        for(int j = 0; j < n; ++j)
        {
            if(matrix[0][j] == 0)
            {
                row = true;
                break;
            }
        }

        // 遍历非 第一行 第一列
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // 非第一列置 0
        for(int i = 1; i < n; ++i)
        {
            if(matrix[0][i] == 0)
            {
                for(int j = 1; j < m; ++j)
                    matrix[j][i] = 0;
            }
        }
        for(int i = 1; i < m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 1; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }
        // 第一行第一列置 0
        if(row)
        {
            for(int i = 0; i < n; ++i)
                matrix[0][i] = 0;
        }
        if(col)
        {
            for(int j = 0; j < m; ++j)
                matrix[j][0] = 0;
        }
    }
};


class Solution2
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row(m), col(n);
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        for(int i = 0; i < m; ++i)
        {
            if(row[i] == 1)
            {
                for(int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 0; j < n; ++j)
        {
            if(col[j] == 1)
            {
                for(int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
            }
        }
    }
};

int main()
{

    return 0;
}