#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回能够覆盖的最大人口数量
     * @param populationDistribute int整型vector 人口覆盖情况
     * @param stationCoverage int整型 公交站覆盖范围
     * @return int整型
     */
    int GetMaxCoverage(vector<int> &populationDistribute, int stationCoverage)
    {
        // write code here
        int n = populationDistribute.size();
        int start = stationCoverage, end = n - 1 - stationCoverage;
        vector<int> sum(n, 0);
        sum[0] = populationDistribute[0];
        for (int i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + populationDistribute[i];
        vector<int> res;
        for (int i = start; i <= end; ++i)
        {
            int ans = sum[i + stationCoverage] - ((i - stationCoverage) == 0) ? 0 : sum[i - stationCoverage - 1];
            res.push_back(ans);
        }
        sort(res.begin(), res.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < res.size(); ++i)
        {
            if (i >= 4)
                break;
            ans += res[i];
        }
        return ans;
    }
};

int main()
{

    return 0;
}