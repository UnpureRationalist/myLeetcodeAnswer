#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool check(int i, double d)
{
    if (i >= 0 && i <= 99 && d >= 0 && d <= 1e9)
        return true;
    return false;
}

int main()
{
    int i;
    double x;
    char c;
    cin >> i >> c >> x;
    if (!check(i, x))
    {
        cout << "null" << endl;
    }
    else
    {
        double res;
        vector<vector<double>> matrix(i + 1, vector<double>(i + 1, 0));
        matrix[0][0] = x;
        for (int j = 1; j <= i; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                if (k == 0 || k == j)
                {
                    if (k == 0)
                    {
                        if (matrix[j - 1][0] > 1)
                        {
                            matrix[j][k] = (matrix[j - 1][0] - 1) / 2;
                        }
                    }
                    if (k == j)
                    {
                        if (matrix[j - 1][j - 1] > 1)
                        {
                            matrix[j][k] = (matrix[j - 1][j - 1] - 1) / 2;
                        }
                    }
                }
                else
                {
                    if (matrix[j - 1][k - 1] > 1)
                    {
                        matrix[j][k] += (matrix[j - 1][k - 1] - 1) / 2;
                    }
                    if (matrix[j - 1][k] > 1)
                    {
                        matrix[j][k] += (matrix[j - 1][k] - 1) / 2;
                    }
                }
            }
        }
        double max_value = 0;
        double min_val = 1;
        for (int j = 0; j <= i; ++j)
        {
            // cout << "matrix[i][j] = " << matrix[i][j] << "  ";
            if (matrix[i][j] > 1)
                max_value = 1;
            else if (matrix[i][j] > max_value)
                max_value = matrix[i][j];
            if (matrix[i][j] < min_val)
                min_val = matrix[i][j];
        }
        // cout << "\nmax = " << max_value << endl;
        // cout << "min = " << min_val << endl;
        res = max_value - min_val;
        cout << fixed << setprecision(4) << res << endl;
    }
    return 0;
}