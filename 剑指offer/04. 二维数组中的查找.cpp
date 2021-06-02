#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix.empty() ? 0 : matrix[0].size();
        int i = 0,j = col - 1;
        while(i >= 0 && i < row && j >= 0 && j < col)
        {
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] < target)
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}