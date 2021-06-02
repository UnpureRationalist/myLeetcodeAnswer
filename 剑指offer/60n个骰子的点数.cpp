#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
    把n个骰子扔在地上，所有骰子朝上一面的点数之和为 s 。
    输入n，打印出s的所有可能的值出现的概率。

    你需要用一个浮点数数组返回答案，其中:
    第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
*/

/*
    问题分析：
        扔 n 个骰子，点数范围为：n ~ 6*n
        每一个骰子的取值范围都是 1-6 ,因此共有 6^n 种情况
*/

class Solution
{
    vector<int> calculate(int n)
    {
        vector<vector<int>> res(n + 1, vector<int>(6 * n + 1, 0));
        for (int i = 1; i <= 6; ++i)
            res[1][i] = 1;
        for (int i = 2; i <= n; ++i)
        {
            int low = i;
            int high = 6 * i;
            int mid;
            if (i % 2 == 0)
                mid = i + (5 * i + 1) / 2;
            else
                mid = i + (5 * i + 1) / 2 - 1;
            for (int j = low; j <= mid; ++j)
            {
                int upper = min(j, 6);
                for (int k = 1; k <= upper && j - k >= 0; ++k)
                    res[i][j] += res[i - 1][j - k];
            }
            for (int j = mid + 1; j <= high; ++j)
                res[i][j] = res[i][7 * i - j];
        }
        return res[n];
    }

public:
    vector<double> dicesProbability(int n)
    {
        int length = 5 * n + 1;
        double base = pow(6, n);
        vector<double> res(length);
        vector<int> frequency = calculate(n);
        for (int i = 0; i < length; ++i)
        {
            res[i] = frequency[i + n] / base;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<double> res = s.dicesProbability(4);
    for (auto &elem : res)
        cout << elem << " ";
    cout << endl;
    return 0;
}