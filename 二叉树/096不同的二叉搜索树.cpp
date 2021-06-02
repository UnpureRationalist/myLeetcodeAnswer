#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        if (n < 3)
            return n;
        vector<int> v(n + 1);
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        for (int i = 4; i <= n; ++i)
        {
            v[i] += v[i - 1]; // 1 作为根节点
            for (int j = 2; j < i; ++j)
            {
                v[i] += v[j - 1] * v[i - j]; // 排列组合（乘法原理）
            }
            v[i] += v[i - 1]; // i 作为根节点
        }
        return v[n];
    }
};

int main()
{

    return 0;
}