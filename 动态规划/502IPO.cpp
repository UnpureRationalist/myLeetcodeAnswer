#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        vector<pii> arr;

        for (int i = 0; i < n; ++i)
        {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end()); // 按照启动资本从小到大排序
        while (k--)
        {
            while (curr < n && arr[curr].first <= w)
            {
                pq.push(arr[curr].second);
                curr++; // 对于所有启动资本小于等于 w 的项目，把它们的 profits 放入大顶堆
            }
            if (!pq.empty())
            {
                w += pq.top(); // 贪心 获取可选择项目的最大利润
                pq.pop();
            }
            else
            {
                break;
            }
        }
        return w;
    }
};

int main()
{

    return 0;
}