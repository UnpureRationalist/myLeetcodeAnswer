#include <iostream>
#include <vector>
using namespace std;
/*
    若二维矩阵为 m 行 n 列
    设行为 row ，列为 col
    则转化为一维数组， index = col + row * n

    反过来，对于一个一位数组下标 index ，转化为 m 行 n 列的二维数组，有：
        col = index % n
        row = index / n
*/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = m != 0 ? matrix[0].size() : 0;
        if (n == 0)
            return false;
        int i = 0, j = m * n - 1;
        int mid;
        while (i <= j)
        {
            mid = (i + j) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] < target)
                i = mid + 1;
            else if (matrix[row][col] > target)
                j = mid - 1;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << s.searchMatrix(matrix, 3) << endl;
    return 0;
}