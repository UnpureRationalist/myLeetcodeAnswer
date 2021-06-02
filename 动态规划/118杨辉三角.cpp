#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i)
            res[i].resize(i + 1);
        for (int i = 0; i < numRows; ++i)
        {
            res[i][0] = 1;
            res[i][i] = 1;
        }
        for (int i = 2; i < numRows; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}