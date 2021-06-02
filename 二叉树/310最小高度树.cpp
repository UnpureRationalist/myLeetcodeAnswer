#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        // 坑：注意边缘情况，目前实现无法覆盖
        if (n == 1)
        {
            return {0};
        }
        else if (n == 2)
        {
            return {0, 1};
        }
        // 构建入度和图
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (vector<int> &edge : edges)
        {
            ++indegree[edge[0]];
            ++indegree[edge[1]];
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // 初始化插入入度为1的结点
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 1)
            {
                q.push(i);
            }
        }

        // 拓扑排序
        while (n > 2)
        {
            n -= q.size();
            for (int i = q.size(); i > 0; --i)
            {
                int curr = q.front();
                q.pop();
                // 入度其实就设置成了0
                indegree[curr] = 0;
                for (int next : graph[curr])
                {
                    // 只考虑入度不为0的情况,即没有被遍历过
                    if (indegree[next] != 0)
                    {
                        --indegree[next];
                        if (indegree[next] == 1)
                        {
                            q.push(next);
                        }
                    }
                }
            }
        }

        // 队列里剩下的元素就是根节点
        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main()
{

    return 0;
}