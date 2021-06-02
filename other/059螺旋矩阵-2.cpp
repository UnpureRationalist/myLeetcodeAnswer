#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        int MAX = n * n;
        int i = 0, j = 0;
        int l = 0, r = n, up = 0, down = n;
        while (num <= MAX)
        {
            // 右
            while (j < r)
            {
                res[i][j] = num;
                num++;
                j++;
            }
            up++;
            j--;
            i++;
            // 下
            while (i < down)
            {
                res[i][j] = num;
                num++;
                i++;
            }
            r--;
            i--;
            j--;
            // 左
            while (j >= l)
            {
                res[i][j] = num;
                num++;
                j--;
            }
            j++;
            down--;
            i--;
            // 上
            while (i >= up)
            {
                res[i][j] = num;
                num++;
                i--;
            }
            i++;
            l++;
            j++;
        }
        return res;
    }
};

int main()
{

    return 0;
}