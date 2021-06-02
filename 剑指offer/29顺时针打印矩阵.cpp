#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = (row == 0 ? 0 : matrix[0].size());
        int i = 0, j = 0;
        vector<int> res;
        int count = 0;
        int MAX = row * col;
        int r = col, l = 0, d = row, u = 0;
        while (count < MAX)
        {
            while (j < r && count < MAX)
            {
                res.push_back(matrix[i][j]);
                j++;
                count++;
            }
            u = u + 1;
            j--;
            i++;
            while (i < d && count < MAX)
            {
                res.push_back(matrix[i][j]);
                i++;
                count++;
            }
            d = d - 1;
            i--;
            j--;
            while (j >= l && count < MAX)
            {
                res.push_back(matrix[i][j]);
                j--;
                count++;
            }
            l = l + 1;
            j++;
            i--;
            while (i >= u && count < MAX)
            {
                res.push_back(matrix[i][j]);
                i--;
                count++;
            }
            r = r - 1;
            i++;
            j++;
        }
        return res;
    }
};

int main()
{

    return 0;
}